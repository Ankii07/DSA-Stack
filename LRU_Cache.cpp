// Brute force solution of LRU Cache problem..

// question badhiya hai maja aayega..

// phle burte force krenge ..
// phir brute force mai kya kya kamiya hai use thik krte huae optimal pe jayenge..

// get(int key){
        // phle iterate kre apne vector pe tabhi to pta chalega key persent hai bhi ki nhi..
        // agr key mil gya to use ek variable mai store kr lenge jisse ki baad mai use return kr paye
        // ab mil to gya hai aur kyuki yh ab recenty used hua hai to khuch aisa krenge jisse ki yh pta chal paye ki yh recently used hua hai..
        // iske liye yha jo tarika use hua hai ki usko vector ke current position se erase krke vector ke piche mai push kr denge..is cheez se hum yh maintain kr paa rhe hai ki jo recently used hai wh vector ke piche hai
        // aur jo least recenty used hai wh automatically vector ke aage mai jo ki hum aage easily pop kr skte hai.. 

        // erase (i)
        // push_back({key, value})

        // agr key persent hi nhi rha to ghanta khuch kroge..
        // direct return -1 kr do..

// }

// ab put function dekh lete hai..

//   put(int key, int value){
        //    agr phle se hi persent hai to put to nhi krenge..
        // uski jo value hai use update kr denge..
        // aur ab kyuki yh recently used hua hai ab khuch aise krenge ki yh pata chal paye ki yh recently use hua hai..
        // uske liye jo trika hum phle use kr rhe the whi use krenge jo ki uska current position hai usko wha se erase kr denge.. aur vector ke piche push kr denge..

        // ith erase && push_back();

        // ab agr nhi mila to ..
            //   to ab check krenge  vector mai jgh bhi hai ..yani size jada to nhi ho gyi capacity se..
            // agr size jada ho gya hai yani uske liye jgh bnani pdegi..jisse ki use daal paye..
            // to hume delete krna pdega koi value..
            // ab delete bhi wh krenge..jo sbse der se use  hua hai..
            // sara khel isi cheez ko maintain krne ka to hai..as our logic wh vector ke front pe hi hoga..
            // wha se usko erase kr denge.. erase(cache.begin)

            // aur jo value jisko put krni hai usko vector ke back mai push kr denge..
            // aur back mai push kyu krenge front mai kyu nhi..ab tak to pta chal hi gya hoga..to maintain the recenty use..
            // push_back(key_value);
// }
        // main point to be noted my lord. 
        //  least recently used (front)
        // most recently used (back)

        class LRUCache {
            public:
                //  initializing vector to maintain least and most recently used cache
                vector<pair<int,int>> cache;
                int n;
                
                LRUCache(int capacity) {
                     n = capacity;   
                }
                
                int get(int key) {
                    // iterating over the vector to find the key is persent or not..
                    for(int i=0; i<cache.size(); i++){
                        // agr persent hai..
                        if(cache[i].first == key){
                        // getting the value so that we can return it later..
                        // yhi se return nhi kr skte kyuki hume yh bhi to mark krna hai ki yh recently used hua hai..
                       int val = cache[i].second;
                       //  aur ab jis pair mai key mila hai to erase krke back mai dalna hai to mark it recently used..
                       //  aur kyuki erase krna hai to andhe ki trah direct erase thori kr doge..kyuki baad mai back mai push bhi to  krna hai ..
                       //  uske liye phle temp mai store kroge..jisse ki tum usse baad mai use kr pao..
                       pair<int, int> temp = cache[i];
                        // ab erase krna hai aur vector mai erase kaise krte hai yh to pata hoga nhi..
                        // aise krte hai seekh lo..phle vector ke starting yani begining ka address nikalenge jo ki hume cache.begin() se mil jayega.
                        // phir usme +i kr denge jisse ki usko current position ka address mil jaye..
                       cache.erase(cache.begin()+i);
                        // now push it in the back of the vector..
                        // aaya temp use yha pe..just like swapping two numbers..
                        cache.push_back(temp);
                        // ab ho gya sara kaam..ab value jo store kr rakha hai use return kr do..
                       return val;
            
                       }
                    }
                    // ab persent hi nhi hai to ghanta return kroge ..nhi -1 return krna hai ..question mai diya hua hai..
                    // dikhai nhi de rha kya..shi mai andhe ho kya..hahaahahaa..just take it as a joke..
                    return -1;
                }
            
                // ab aa jao put ka bhi kiya kalap kr dete hai..
                // yha tk to samajh mai aa gya hoga..agr nhi aaya to hum khuch nhi kr skte..
            
                void put(int key, int value) {
                    //  ab yha pe sabse phle yh check krna hai ki key khi phle se persent to nhi ..jiske liye loop lagega..
                    // agr persent hai to current position se erase krenge aur uske value ko update krke piche mai daal denge..phiche matlb..
                    for(int i=0; i< cache.size(); i++){
                        // value phle se hi persent hai
                        // mil gyi value..
                       if(cache[i].first == key){
                        // ab tk erase krna aa hi gya hoga..
                         cache.erase(cache.begin()+i);
                        //push it in the back..  
                         cache.push_back({key, value});
                        //  return ho jaye.
                         return;
                       }
                    }
                    //  ab phle se to persent hai nhi..
                    // agr ab size full ho gya ho to jgh bnane ke liye delete krna hoga..
                    // delete to front se hi krenge..ab tk to pta chal hi gya hoga.. 
                    // aur piche daal denge..
                    if(cache.size() == n){
                        // aage se delete kre
                      cache.erase(cache.begin());
                    //   aur piche mai daal de..
                      cache.push_back({key, value});
                    }
                    // ab phle se persent bhi nhi hai aur jgh bhi hai..to bs kya krnna hai..
                    // piche mai daal do..
                    else{
                        cache.push_back({key, value});
                    }
            
                    // ho gya sara kaam maje kro ab..
            
                }
            };
            // abhi to lg rha hoga ho gya sara kaamm nhi bhai saab aise thodi hi hard marked hai..
            // pta hai itna krne ke baad bhi leetcode ko santoshti nhi milegi..wh tle dega..
            // ab is tle se deal krne ke liye hum khuch trike nikalenge..
            // wh ek is trike se ho skta hai ki kum se kum se calcultation krna pde ya traverse krna pde..
            
            // time complexity..
            // yha pe time complexity O(n^2) 
            // kyuki ek traverse krna to pd hi rha yh pata lagane ke liye key persent hai bhi ki nhi aur..
            // aur milne ke baad usko current position se delete bhi kr rhe hai..erase krne vector mai time complexity hoti hai O(n)..
            // aur push to O(1) mai hi ho jati hai.. 
            
            
            /**
             * Your LRUCache object will be instantiated and called as such:
             * LRUCache* obj = new LRUCache(capacity);
             * int param_1 = obj->get(key);
             * obj->put(key,value);
             */


//  Optimal solution


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