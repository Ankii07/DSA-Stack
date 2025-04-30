// ab hum optimal solution dekhenge..
// brute force mai kya kya problem thi..usko ek ek krke dekhenge..
// aur usse ek ek solve krke optimal solution pe phuchenge..

// yh to pata hona chahiye ki time limit exceed aati kyu hai ..
// jb aapka solution given constraint se jada complexity ka ho ya jada traversal ho rhe ho,complex operation ho rhe ho vagera vagera..

// 1st problem in the brute force..
// erase function bhut hi complex operation aur heavy operation hai kyuki erase option mai values ko shift bhi krna hota hai..
// khuch aisa data structure ke bare mai shochenge jisme data lineary store ho jaye. aur uske erase bhi easily ho jaye..
// aise hum list yani linked list ka use kr skte hai ..kyuki isme easily delete bhi kr skte hai aur sare values ko shift bhi nhi krna padega.. 
// ab delete krna hai to uske previous element ka address bhi pata hona chahiye..to simple linked list mai to yh nhi kr skte ..isiliye doubly linked list maintain krna hoga..

// 2nd problem..
// erase easy to ho gya hai..pr traverse krna pdega to find the key ..usme bhi O(n) lagega..
// isme yh kr skte hai aise khuch maintain jisse mai key ke sath uska address satth mai hi ho jisse ki directly hi uske pass phuch jaye..
// to ek map maintain kr lenge..uske address aur uske values ke saath..
// yha pe space complexity badh rhi hai pr time complexity ko maintain krna hai to space complexity ko maintain to krna hi padega..

// 3rd problem..
// agr doubly linked list mai as per traditional back mai push kre to delete krne liye bhi back tk jana hoga.. 
// iske liye hum front mai hi push kr lenge..jisse ki hum easily pop kr paye..using doubly linked list stl which is provided by c++..

class LRUCache {
    public:
        // doubly linked list to store the cache/key..
        list<int> dll;
        // map to sotre key with it's address and value..
        // address of the node of the linked list.. list<int>::iterator
        map<int, pair<list<int>:: iterator, int>> mp;
        // to monitor the capacity..
        int n;
        LRUCache(int capacity) {
            n= capacity;
        }
    
        void makeRecentlyUsed(int key){
            // recently marked krne ke liye us key ko uske current position se erase krke doubly linked list ke
            // front mai daal denge..
    
            // deleting it from it's current position ...erase provided by c++ stl
            dll.erase(mp[key].first);
    
            // and pushind it in the front of the doubly linked list..
            dll.push_front(key);
    
            // now the address of the key has changed so update in the map as well..
            // front mai dalne ke fayda yh hai ki hum uska address mil ja rha hia dll.begin se..yhi agr back mai 
            // rhta to traverse krke uske pass jana padta..
            mp[key].first = dll.begin();
        }
        
        int get(int key) {
            // if key is not persent return -1;
            if(mp.find(key) == mp.end())
             return -1;
            //  if persent mark it Recently used
            makeRecentlyUsed(key);
            // returning the value of the key from the map stored. 
             return mp[key].second;
        }
        
        void put(int key, int value) {
            // if key allready persent
            // just updates its value in the map..
            // and mark it most recently used..
            if(mp.find(key) != mp.end()){
                mp[key].second = value;
                makeRecentlyUsed(key);
            }
            // if not persent
            else{
            //  push it in the front.
            dll.push_front(key);
            // update in the map..all the changes should be updated in the map..
             mp[key] ={dll.begin(), value};
            //  decrement the capacity..
             n--;
            }
            //  if dll is exceeding the capacity then we will delete it from the back..
            if(n <0){
                // key to be deleted
                int key_tobe_del = dll.back();
                // deleting the key from the map..
                mp.erase(key_tobe_del);
                // deleting it from the dll as well..
                dll.pop_back();
                // now there is a space so increment the n..
                n++;
            }
    
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */