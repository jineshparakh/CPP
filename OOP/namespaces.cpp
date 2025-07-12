#include<bits/stdc++.h>
using namespace std;
namespace Jinesh {
int x;
void fun();
class Jinesh {
public:
	void jinesh();
};
}
void Jinesh::fun() {
	cout << "Accessing fun() function from Jinesh Namespace\n";
}
void Jinesh::Jinesh::jinesh() {
	cout << "Accessing jinesh() function from Jinesh class inside Jinesh namespace\n";
}
int main() {
	/*
	    namespace
	        --> It is a container for identifiers
	        --> It puts the names of it's members in a distinct space so that they don't conflict
	            with the names in other global namespace

	    How to create namespace?
	        Syntax:
	            namespace namespaceName{
	                //Declarations
	            }
	    IMP Points:
	        --> The namespace definition must be done at global scope, or nested inside other namespace
	        --> You can use an alias name for a namespace
	            namespace AliasName=namespaceName
	        --> It is not a class so object cannot be created
	        --> There can be unnamed namespaces
	            Syntax:
	                namespace{
	                    // Declarations
	                }
	        --> A namespace definiton can be extended or continued to multiple files, they are not
	            overwritten or redefined

	    using directive:
	        --> using keyword allows a programmer to import an entire namespace into the program
	            with a global scope
	        --> It can be used to import namespaces into another namespaces or programs


	*/
	Jinesh::x = 2;
	Jinesh::fun();
	Jinesh::Jinesh j;
	j.jinesh();
}