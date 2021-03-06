// #include "Schema.h"
// #include "Function.h"
// #include "Comparison.h"
#include "ParseNode.h"
#include <iostream>
#include <vector>

using namespace std;

ParseNode::ParseNode(){

	lChildPipeID = 0;
	rChildPipeID = 0;
	outPipeID = 0;

	parent = NULL;
	left = NULL;
	right = NULL;

	schema = NULL;
}

ParseNode::~ParseNode(){
}

void ParseNode::SetType(ParseNodeType setter){
	type = setter;
}

void ParseNode::GenerateSchema(){
	Schema *lChildSchema = left->schema;
	Schema *rChildSchema = right->schema;
	schema = new Schema(lChildSchema, rChildSchema);
}

void ParseNode::GenerateFunction(){
	func = new Function();
	func->GrowFromParseTree(funcOp, *schema);
}

void ParseNode::GenerateOrderMaker(int numAtts, vector<int> whichAtts, vector<int> whichTypes){
		order = new OrderMaker();
		order->numAtts = numAtts;
		for(int i = 0; i < whichAtts.size(); i++){
			order->whichAtts[i] = whichAtts[i];
			order->whichTypes[i] = (Type)whichTypes[i];
		}
}

void ParseNode::PrintInOrder(){
	if(NULL != left){
		left->PrintInOrder();
	}
	if(NULL != right){
		right->PrintInOrder();
	}
	cout << "**********" << endl;
	PrintNode();
	cout << "**********" << endl;
}

void ParseNode::PrintNode(){
  cout << GetTypeName() << " Relational operation" << endl;
  switch (type){
    case SELECTF:
		cout << "Input Pipe ID - " << lChildPipeID << endl;
		cout << "Output Pipe ID - " << outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;
		schema->Print();
		PrintCNF();
      break;

    case SELECTP:
		cout << "Input Pipe ID - " << lChildPipeID << endl;
		cout << "Output Pipe ID - " << outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;
		schema->Print();
		cout << "SELECTION CNF :" << endl;
		PrintCNF();
      break;

    case PROJECT:
		cout << "Input Pipe ID - " << lChildPipeID << endl;
		cout << "Output Pipe ID - "<< outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;
		schema->Print();
		cout << endl << "************" << endl;
      break;

    case JOIN:
		cout << "Left Input Pipe ID - " << lChildPipeID << endl;
		cout << "Right Input Pipe ID - " << rChildPipeID << endl;
		cout << "Output Pipe ID - " << outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;
		schema->Print();
		cout << endl << "CNF: " << endl;
		PrintCNF();
      break;

    case SUM:
		cout << "Left Input Pipe ID - " << lChildPipeID << endl;
		cout << "Output Pipe ID - " << outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;
		schema->Print();
		cout << endl << "FUNCTION: " << endl;
		PrintFunction();
      break;

    case DISTINCT:
		cout << "Left Input Pipe ID - " << lChildPipeID << endl;
		cout << "Output Pipe ID - " << outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;	
		schema->Print();
		cout << endl << "FUNCTION: " << endl;
		PrintFunction();
	break;

    case GROUP_BY:
		cout << "Left Input Pipe ID - " << lChildPipeID << endl;
		cout << "Output Pipe ID - " << outPipeID << endl;
		cout << "OUTPUT SCHEMA: " << endl;	
		schema->Print();
		cout << endl << "GROUPING ON " << endl;
		order->Print();
		cout << endl << "FUNCTION " << endl;
		PrintFunction();
      break;

    case WRITE:
		cout << "Left Input Pipe ID - " << lChildPipeID << endl;
		cout << "OUTPUT FILE " << path << endl;
      break;

   }
}

string ParseNode::GetTypeName(){
  string name;
  switch (type){

    case SELECTF:
      name = "SelectFile";
      break;

    case SELECTP:
      name = "SelectPipe";
      break;

    case PROJECT:
      name = "Project";
      break;

    case JOIN:
      name = "Join";
      break;

    case SUM:
      name = "Sum";
      break;

    case GROUP_BY:
      name = "GroupBy";
      break;

    case DISTINCT:
      name = "Distinct";
      break;

    case WRITE:
      name = "Write";
      break;
  } 
  return name;
} 

void ParseNode::PrintCNF(){
  if (cnf){
    struct AndList *curAnd = cnf;
    struct OrList *curOr;
    struct ComparisonOp *curOp;
    while (curAnd){
      curOr = curAnd->left;
      if (curAnd->left){
			cout << "(";
      }
      while (curOr){
			curOp = curOr->left;
			if (curOp){
			  if (curOp->left){
			    cout << curOp->left->value;
			  }
			  switch (curOp->code){
			    case 5:
			      cout << " < ";
			      break;
			    case 6:
			      cout << " > ";
			      break;
			    case 7:
			      cout << " = ";
			      break;
			  } 

			  if (curOp->right){
			    cout << curOp->right->value;
			  }
			} 
			if (curOr->rightOr){
			  cout << " OR ";
			}
			curOr = curOr->rightOr;
      } 
      if (curAnd->left){
			cout << ")";
      }
      if (curAnd->rightAnd) {
			cout << " AND ";
      }
      curAnd = curAnd->rightAnd;
    } 
  } 
   cout << endl;
}

void ParseNode::PrintFunction(){
	func->Print();
}