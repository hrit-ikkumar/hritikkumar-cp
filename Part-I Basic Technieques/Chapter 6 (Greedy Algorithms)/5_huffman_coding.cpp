// @hritikkumar
#include<bits/stdc++.h> // all header files

#define endl '\n'
#define MAX_TREE_HT 100

using namespace std; //namespace created as std

// user defined data type for node
struct Node {
	char data;
	unsigned freq;
	struct Node* left, *right;
	
	Node(char d, unsigned f)
	{
		left = right = NULL;
		this->data = d;
		this->freq = f;
	}
};

void printHuffmanCodes(Node* , string, vector<pair<char, string>> &ans); // function for printing pattern for particuler code

vector<pair<char, string> > huffmanCoding( char *,int *, int );

int main(void)
{
	std::ios::sync_with_stdio(false);  cin.tie(0); // fastio
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif
	int n;
	cin>>n;
	char* data = new char [n];
	int* freq = new int[n];
	for(int i = 0 ; i<n;i++) cin>>data[i]>>freq[i];
	vector<pair<char, string>> ans = huffmanCoding(data, freq, n);
	// If you want to a sorted
	sort(ans.begin(), ans.end(), []( auto a, auto b) { return a.first < b.first; });
	for(pair<char, string> code: ans)
	{
		cout<<code.first<<": "<<code.second<<endl;
	}
	return 0; // return type is int
}

void printHuffmanCodes(Node* root , string curr, vector<pair<char, string>> &ans)
{
	if(!root)
		return;
	else if(root->data != '$')
	{
		ans.push_back({root->data, curr});
	}
	printHuffmanCodes(root->left, curr+'0', ans);
	printHuffmanCodes(root->right, curr+'1', ans);
}

vector<pair<char, string>> huffmanCoding(char * data, int * freq , int n)
{
	Node *left, *right, *top;
	
	auto comp = [] (Node*  a, Node* b) -> bool { return a->freq > b->freq;};
	priority_queue<Node*, vector<Node*>, decltype(comp)> minPQ (comp);
	
	for(int i=0;i<n;i++)
	{
		minPQ.push( new Node(data[i], freq[i]) );
	}
	// constructing the huffman coding tree
	while(minPQ.size() != 1)
	{
		left = minPQ.top();
		minPQ.pop();
		
		right = minPQ.top();
		minPQ.pop();
		
		top = new Node('$', left->freq + right->freq);
		if(left->freq >= right->freq)
		{ 
			top->left = left;
			top->right = right;
		}
		else
		{
			top->left = right;
			top->right = left;
		}
		
		minPQ.push(top);
	}
	vector<pair<char, string>> ans;  // answer 
	
	printHuffmanCodes(minPQ.top(), "", ans);
	
	return ans;
}
