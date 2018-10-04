#include "ExpressionManager.h"  
#include <sstream>
#include <cctype>

// The set of opening parentheses.
const string OPEN = "([{";

// The corresponding set of closing parentheses.
const string CLOSE = ")]}";

bool is_open(char ch) {
    return OPEN.find(ch) != string::npos;
}

bool is_close(char ch) {
    return CLOSE.find(ch) != string::npos;
}

bool openParen(string p) {
  return OPEN.find(p) != string::npos;
}

bool closeParen(string p) {
  return CLOSE.find(p) != string::npos;
}

bool matchParen(string a, string b) {
  if (a == "(" && b == ")") {
    return true;
  }
  else if (a == "{" && b == "}") {
    return true;
  }  
  else if (a == "[" && b == "]") {
    return true;
  }
  else {
    return false;
  }
}

int ExpressionManager::pemdas(string op) {
  if (op == "+" || op == "-") {
    return 1;
  }
  if (op == "*" || op == "/" || op == "%") {
    return 2;
  }
  if (op == ")" || op == "}" || op == "]") {
    return 3;
  }
  else {
    return 0;
  }
}

bool ExpressionManager::isParen(string par){
	if (par == "(" || par == "{" || par == "[" || par == ")" || par == "}" || par == "]"){
		return true;
	}
	else{
		return false;
	}
}

bool ExpressionManager::isBalanced(string expression)
{
    cout << "In isBalanced expression "<<expression<<endl;
    
    stack<char> s;
    bool balanced = true;
    for (string::const_iterator iter = expression.begin();
     balanced && (iter != expression.end());
     iter++) {
        char next_ch = *iter;
        if (is_open(next_ch)) {
            s.push(next_ch);
        } else if (is_close(next_ch)) {
            if (s.empty()) {
                balanced = false;
            } else {
                char top_ch = s.top();
                s.pop();
                balanced = 
                 OPEN.find(top_ch) == CLOSE.find(next_ch);
            }
        }
    }
    return balanced && s.empty();
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
  cout << "In postfixToInfix" <<endl;
	  stack<string> mystack;
	  stringstream ss(postfixExpression);
	  string current;
	  string left;
	  string right;
	  string infix_expression;
	  
	  if(!isBalanced(postfixExpression)) {
	    return "invalid";
	  }
	  
	  while (ss >> current) 
	  {
	    //Check for floating point values
	    if (current.find(".") != string::npos) {
        return "invalid";
      }
	    if (current == "NULL") {
	      return "invalid";
	    }
	    if (isdigit(current[0])) {
	      mystack.push(current);
	    } 
	    else if (is_operator(current[0])) {
	      if (mystack.empty()) {
	        return "invalid";
	      }
	      else {
	        right = mystack.top();
	        mystack.pop();
	        if (mystack.empty()) {
	          return "invalid";
	        }
	        left = mystack.top();
	        mystack.pop();
	        infix_expression = "(" + left + " " + current + " " + right + ")";
	        mystack.push(infix_expression);
	      }
	    }
	    else {
	      return "invalid";
	    }
	  }
    infix_expression = mystack.top();
    mystack.pop();
    //After popping finished infix expression. Check for leftovers on the stack.
    if (!mystack.empty()) {
      return "invalid";
    }
    return infix_expression;
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
  cout << "In postfixEvaluate "<< postfixExpression<< " ";
// Be sure the stack is empty
  while (!operand_stack.empty())
    operand_stack.pop();

  // Process each token
  istringstream tokens(postfixExpression);
  char next_char;
  while (tokens >> next_char) {
    if (isdigit(next_char)) {
      tokens.putback(next_char);
      int value;
      tokens >> value;
      operand_stack.push(value);
    } else if (is_operator(next_char)) {
      int result;
      try {
        result = eval_op(next_char);
      }
      catch(int which) {
          cout << "not enough operands" << endl;
          return("invalid");
      }
      operand_stack.push(result);
    } else {
      cout << "not digit or operand";
      return("invalid");
    }
  }
  if (!operand_stack.empty()) {
    string answer = to_string(operand_stack.top());
    operand_stack.pop();
    if (operand_stack.empty()) {
      return answer;
    } else {
      cout << "at end stack not empty";
      return("invalid");
    }
  } else {
    cout << "at end answer not on stack";
    return("invalid");
  }
}

const std::string ExpressionManager::OPERATORS = "+-*/%";

int ExpressionManager::eval_op(char op) {
  if (operand_stack.empty()) 
    throw 1;
  int rhs = operand_stack.top();
  operand_stack.pop();
  if (operand_stack.empty())
    throw 2;
  int lhs = operand_stack.top();
  operand_stack.pop();
  int result = 0;
  switch(op) {
  case '+' : result = lhs + rhs;
             break;
  case '-' : result = lhs - rhs;
             break;
  case '*' : result = lhs * rhs;
             break;
  case '/' : if (rhs == 0) {throw 3;} result = lhs / rhs;
             break;
  case '%' : result = lhs % rhs;
             break;
  }
  return result;
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
    cout << "In infixToPostfix"<<endl;
    //operator stack
    stack<string> mystack;
    string postfixstring;
    stringstream ss(infixExpression);
    stringstream os;
    string current;
    string top;
    bool prevDigit = false;
    
    if(!isBalanced(infixExpression)) {
      return "invalid";
    }
    while (ss >> current) {
      //If current is a number, push onto stack.
      if (current.find(".") != string::npos) {
        return "invalid";
      }
      if (isdigit(current[0])) {
        //mystack.push(current);
        os << current << " ";
        prevDigit = true;
      }
      //If it is an operator
      else if (is_operator(current[0])) {
        if (prevDigit == false) {
          return "invalid";
        }
        //If stack is empty, push onto stack
        if (mystack.empty()) {
          string temp = os.str();
          if (temp.length() == 0) {
            return "invalid";
          }
          mystack.push(current);
        }
        //If the top of the stack is a paren, push onto stack
        else if (isParen(mystack.top())) {
          mystack.push(current);
        }
        //If the operator precedence of the top is less than current, push onto stack
        else if (pemdas(mystack.top()) < pemdas(current)) {
          mystack.push(current);
        }
        /*Else while the precedence of top is greater than current, convert
        postfix to infix and then push onto stack when finished */
        else {
          while (!mystack.empty() && (pemdas(mystack.top()) >= pemdas(current))) {
            top = mystack.top();
            os << top << " ";
            mystack.pop();
          }
          mystack.push(current);
        }
        prevDigit = false;
      }
      //If it's an open paren, push onto stack
      else if (openParen(current)) {
        mystack.push(current);
      }
      //If closing paren
      else if(closeParen(current)) {
        while(!matchParen(mystack.top(), current)) {
          top = mystack.top();
          os << top << " ";
          mystack.pop();
        }
        mystack.push(current);
        mystack.pop();
        mystack.pop();
      }
      //Else its not a valid operator, paren, or digit
      else {
        return "invalid";
      }
    }
    while(!mystack.empty()) {
      top = mystack.top();
      os << top << " ";
      mystack.pop();
    }
    postfixstring = os.str();
    return postfixstring;
}

