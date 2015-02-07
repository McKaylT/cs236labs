// Robert Williams CS 236

#include "parameter.h"

Parameter::Parameter(Token* token) {
	this->value = NULL;
	this->firstParameter = NULL;
	this->secondParameter = NULL;
	this->operatorToken = NULL;
	if (token != NULL) this->terminal(token);
}

Parameter::~Parameter() {
}

void Parameter::expression(Parameter* firstParameter, Token* operatorToken, Parameter* secondParameter) {
	this->type = EXPRESSION;
	this->firstParameter = firstParameter;
	this->secondParameter = secondParameter;
	this->operatorToken = operatorToken;
}

void Parameter::terminal(Token* token) {
	this->type = token->getType();
	this->value = token;
}

string Parameter::toString() {
	if (this->type == EXPRESSION) {
		return "(" + this->firstParameter->toString() + this->operatorToken->getExtracted() + this->secondParameter->toString() + ")";
	}
	return this->value->getExtracted();
}