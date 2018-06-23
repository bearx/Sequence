#include"Sequence.h"
using namespace std;
int main()
{
	Sequence s("dna.txt");
	cout<<s.length()<<endl;
	cout<<"A:"<<s.numberOf('A')<<endl;
	cout<<"T:"<<s.numberOf('T')<<endl;
	cout<<"G:"<<s.numberOf('G')<<endl;
	cout<<"C:"<<s.numberOf('C')<<endl;
	cout<<"longestConsecutive:"<<s.longestConsecutive()<<endl;
	cout<<"longestRepeated:"<<s.longestRepeated()<<endl;
	return 0;
}
