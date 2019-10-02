#include<iostream> 
using namespace std; 

struct Building 
{ 
	int left; 
	int ht; 
	int right; 
}; 


class Strip 
{ 
	int left;
	int ht;  
public: 
	Strip(int l=0, int h=0) 
	{ 
		left = l; 
		ht = h;

	} 
	friend class SkyLine; 
}; 

class SkyLine 
{ 
	Strip *arr; 
	int capacity;
	int n; 
public: 
	~SkyLine() { delete[] arr; } 
	int count() { return n; } 

	SkyLine* Merge(SkyLine *other); 

	SkyLine(int cap) 
	{ 
		capacity = cap; 
		arr = new Strip[cap]; 
		n = 0; 
	} 

	void append(Strip *st) 
	{ 
		if (n>0 && arr[n-1].ht == st->ht) 
			return; 
		if (n>0 && arr[n-1].left == st->left) 
		{ 
			arr[n-1].ht = max(arr[n-1].ht, st->ht); 
			return; 
		} 

		arr[n] = *st; 
		n++; 
	} 

	void print() 
	{ 
		for (int i=0; i<n; i++) 
		{ 
			cout << " (" << arr[i].left << ", "
				<< arr[i].ht << "), "; 
		} 
	} 
}; 

SkyLine *findSkyline(Building arr[], int l, int h) 
{ 
	if (l == h) 
	{ 
		SkyLine *res = new SkyLine(2); 
		res->append(new Strip(arr[l].left, arr[l].ht)); 
		res->append(new Strip(arr[l].right, 0)); 
		return res; 
	} 

	int mid = (l + h)/2; 

	SkyLine *sl = findSkyline(arr, l, mid); 
	SkyLine *sr = findSkyline(arr, mid+1, h); 
	SkyLine *res = sl->Merge(sr); 

	delete sl; 
	delete sr; 

	return res; 
} 

SkyLine *SkyLine::Merge(SkyLine *other) 
{
	SkyLine *res = new SkyLine(this->n + other->n); 
	 
	int h1 = 0, h2 = 0; 

	int i = 0, j = 0; 
	while (i < this->n && j < other->n) 
	{ 
	
		if (this->arr[i].left < other->arr[j].left) 
		{ 
			int x1 = this->arr[i].left; 
			h1 = this->arr[i].ht;  
			int maxh = max(h1, h2); 

			res->append(new Strip(x1, maxh)); 
			i++; 
		} 
		else
		{ 
			int x2 = other->arr[j].left; 
			h2 = other->arr[j].ht; 
			int maxh = max(h1, h2); 
			res->append(new Strip(x2, maxh)); 
			j++; 
		} 
	} 

	while (i < this->n) 
	{ 
		res->append(&arr[i]); 
		i++; 
	} 
	while (j < other->n) 
	{ 
		res->append(&other->arr[j]); 
		j++; 
	} 
	return res; 
} 

int main() 
{ 
	Building arr[] = {{33,41,5}, {4,9,21}, {30,36,9}, 
					{14,18,11}, {2,12,14}, {34,43,19}, 
					{23,25,8}, {14,21,16}, {32,37,12}, {7,16,7}, {24,27,10}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	SkyLine *ptr = findSkyline(arr, 0, n-1); 
	cout << " Skyline for given buildings is \n"; 
	ptr->print(); 
	return 0; 
} 
