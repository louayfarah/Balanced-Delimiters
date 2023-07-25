//Louay Farah
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second
 
//linked list data structure
template<typename T> class LinkedList{
    public:
        //node class
        class token{
            public:
                T value;
                token* last = NULL;
                token* next = NULL;
                token(T val){
                    value = val;
                }
        };
 
        int size = 0;
        token* head;
        token* tail;
 
        LinkedList(){
            head = NULL;
            tail = NULL;
        }
 
        void push(T value);
        void pop();
        T peek();
        int getIndex(T v);
        T atIndex(int i);
};
 
//push an elemnt value to the tail of the list
template <typename T> void LinkedList<T>::push(T value){
    if(head==NULL){
        head = new token(value);
        tail = head;
        return;
    }
    token* newtoken = new token(value);
    tail->next = newtoken;
    newtoken->last = tail;
    tail = newtoken;
    size++;
}
 
//pop an element from the end of the list
template <typename T> void LinkedList<T>:: pop(){
    if(head == tail){
        head = NULL;
        tail = NULL;
        return;
    }
    tail = tail->last;
    tail->next = NULL;
}
 
//return the tail of the list
template <typename T> T LinkedList<T>:: peek(){
    return tail->value;
}
 
//Get the index of element v
template <typename T> int LinkedList<T>:: getIndex(T v){
    if(head==NULL) return -1;
    int c = 0;
    token* temp = head;
    while(temp!=NULL){
        if(temp->value == v){
            return c;
        }
        c++;
        temp = temp->next;
    }
    return -1;
}
 
//Get the element at index i
template <typename T> T LinkedList<T>::atIndex(int i){
    token* temp = head;
    while(i--){
        temp = temp->next;
    }
    return temp->value;
}
 
//Stack data structure
template <typename T> class MyStack
{
private:
    int size = 0;
public:
    LinkedList<T> arr;
    void push(T elt);
    void pop();
    T top();
    int stackSize();
    bool empty();
};
 
//push an element to the top
template <typename T> void MyStack<T>::push(T elt)
{
    MyStack::arr.push(elt);
    MyStack::size++;
}
 
//pop an element from the top
template <typename T> void MyStack<T>::pop()
{
    MyStack::arr.pop();
    MyStack::size--;
}
 
//return the top of the stack
template <typename T> T MyStack<T>::top()
{
    return arr.peek();
}
 
//return the size of the stack
template <typename T> int MyStack<T>::stackSize()
{
    return MyStack::size;
}
 
//return true if the stack is empty, and false else
template <typename T> bool MyStack<T>::empty()
{
    return (MyStack::size == 0);
}
 
//Hash map data structure
template <typename K, typename V> class MyHashMap
{
private:
    int size = 0;
    int capacity = 100;
public:
    vector<vector<pair<K, V>>> table;
    void init();
    int hashFunction(K key);
    void put(K key, V value);
    void remove(K key);
    V get(K key);
    int hashMapSize();
    bool isEmpty();
};
 
//initialize the hashmap
template <typename K, typename V> void MyHashMap<K, V>::init()
{
    table.assign(capacity, {});
}
 
//the hash function
template <typename K, typename V> int MyHashMap<K, V>::hashFunction(K key)
{
    int x = 0;
    for(auto elt: key)
    {
        x = ((x%capacity) + (elt%capacity))%capacity;
    }
 
    return x%capacity;
}
 
 
//put a key-value pair in the hashmap
template <typename K, typename V> void MyHashMap<K, V>::put(K key, V value)
{
    int index = MyHashMap::hashFunction(key);
    MyHashMap::remove(key);
    MyHashMap::table[index].push_back(mp(key, value));
}
 
//remove a key-value pair from the hashmap
template <typename K, typename V> void MyHashMap<K, V>::remove(K key)
{
    int index = MyHashMap::hashFunction(key);
    if(!MyHashMap::table[index].empty())
    {
        for(int i = 0; i<int(MyHashMap::table[index].size()); i++)
        {
            if(MyHashMap::table[index][i].fi == key)
            {
                MyHashMap::table[index].erase(MyHashMap::table[index].begin()+i);
                break;
            }
        }
    }
}
 
//get the value of key k
template <typename K, typename V> V MyHashMap<K, V>::get(K key)
{
    int index = MyHashMap::hashFunction(key);
    if(!MyHashMap::table[index].empty())
    {
        for(int i = 0; i<int(MyHashMap::table[index].size()); i++)
        {
            if(MyHashMap::table[index][i].fi == key)
            {
                return MyHashMap::table[index][i].se;
            }
        }
    }
 
    return 0;
}
 
//return the size of the hashmap
template <typename K, typename V> int MyHashMap<K, V>::hashMapSize()
{
    return MyHashMap::size;
}
 
//return true if the hashmap is empty, and false else
template <typename K, typename V> bool MyHashMap<K, V>::isEmpty()
{
    return (MyHashMap::size == 0);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
 
    MyHashMap<string, bool> is_closing, is_openning;
    MyHashMap<string, string> openning_of, closing_of;
 
    is_closing.init();
    is_openning.init();
    openning_of.init();
    closing_of.init();
 
    for(int i = 0; i<n; i++)
    {
        string a, b;
        cin >> a >> b;
 
        openning_of.put(b, a);
        closing_of.put(a, b);
        is_openning.put(a, true);
        is_closing.put(b, true);
    }
 
    MyStack<string> s;
    string sequence;
    getline(cin, sequence);
 
    for(int line = 1; line<=k; line++)
    {
        getline(cin, sequence);
        int len = int(sequence.length());
 
        list<string> tokens;
        int curr = 0;
        while(curr < len)
        {
            string to_add = "";
            while(curr < len)
            {
                if(sequence[curr] == ' ')
                    break;
                to_add.pb(sequence[curr]);
                curr++;
            }
 
            tokens.pb(to_add);
            curr++;
        }
 
        int curr_column = 1;
        for(auto token: tokens)
        {
            if(is_openning.get(token) == true)
            {
                s.push(token);
            }
 
            if(is_closing.get(token) == true)
            {
                if(s.empty())
                {
                    cout << "Error in line " << line << ", column " << curr_column << ": unexpected closing token " << token << '.' << endl;
                    return 0;
                }
                else if(s.top()!=openning_of.get(token))
                {
                    cout << "Error in line " << line << ", column " << curr_column << ": expected " << closing_of.get(s.top()) << " but got " << token << '.' << endl;
                    return 0;
                }
                else
                {
                    s.pop();
                }
            }
 
            curr_column += int(token.length())+1;
        }
    }
 
    if(!s.empty())
    {
        cout << "Error in line " << k << ", column " << int(sequence.size())+2 <<": expected " << closing_of.get(s.top()) << " but got end of input." << endl;
        return 0;
    }
 
    cout << "The input is properly balanced." << endl;
 
    return 0;
}
