
#include<stdlib.h>
#include<iostream>
#include<unordered_map>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode* original = head;
	RandomListNode* clone = NULL;
	unordered_map<RandomListNode*, RandomListNode*> umap;
	
	while(original) {
		clone = new RandomListNode(original->label);
		umap[original] = clone;
		original = original->next;
	}

	original = head;
        
	while(original) {
		clone = umap[original];
		clone->next = umap[original->next];
		clone->random = umap[original->random];
		original = original->next;
	}
	
	return umap[head];
}

int main() {
	RandomListNode* temp = new RandomListNode(1);
	temp->next = new RandomListNode(2);
	temp->next->next = new RandomListNode(3);
	temp = copyRandomList(temp);
	return 0;
}
