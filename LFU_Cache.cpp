// mast question hai maja hi aa jayega..
// yh question least recently used ka updated version hai..to phle us question ko kr rakha hona jurroi hai..


class LFUCache {
    public:
        //to store the capacity.. 
        int cap ;
        // to keep track of the size of the cache..
        int size;
        // ek unordered map rakhenge jo track rakhega key ka aur uske address jisse ki us doubly linked node ko point kr ske directly
        // jb hume uska use pde.. 
        // Address :-> list<vector<int>>:: iterator
        unordered_map<int, list<vector<int>>:: iterator> mp;  //key -> Address
    
        // yha pr hi ek major change hai compared to LRU ..
        // LRU mai to overall ek hi doubly linked list ko mainatain kr rhe the aur usi mai utha patk i mean position change krke
        // least recently used maintain kr le rhe the..jo ki hum yha pe bhi krenge..but not in that utha patk way..just by pushing the element at the front aur jo most
        // recently used hoga to uske back se pop kr denge..
    
        // pr yha pe hum kya kr rhe hr ek use count ke crossponding ek doubly linked list maintain kr rhe same use count ke sath..
        // aisa krne ka main reason yh hai ki hume tie break ka baare mai bhi care krna hai..
        // agr nhi krna hota to hum LRU wale logic pe soch skte the...
    
        // aur doubly linked ke node mai ek vector hoga jisme ki {key, value, counter} ko maintain krenge..
        // counter ko isiliy maintain krna pd rha hai kyuki usi ke help se hume yh pata chalega ka yh node kis counte ke crossponding map stored hai.aur use increenment bhi krte rhenge.
    
        // aur sbse important baat is map ko ordered rakhna hai kyuki jb delete krne ki baadi aaye to hum sbse pahle wale entry ko delete kr de..
        // kyuki yh ordered hai to sbse phle wala sbse least rhega..
    
        // map<count, doubly linked>
        // aur doubly linked list hi kyu use kr rhe hai..yh aapko LRU mai pta chalega..
        map<int, list<vector<int>>> freq;
    
        LFUCache(int capacity) {
            cap = capacity;
            size = 0;
        }
        
        void makeMostFrequentlyUsed(int key){
            // MostFreqeuntlyUsed banane ke liye sabse phle..
            // hum us node pe point krenge aur usko refrence se trigger krenge kyuki hum chahte jo hum yha 
            // change kre us address pe bhi reflect ho jo ki bhut jurrori hai..
             
            // node at that address which is a vector
            auto &vec = *(mp[key]);
    
            // so take out the value from that address..which at index 1
            int value =vec[1];
            //  now we have to take out frequency ..
            // isilye maintain kiya gya tha ki increement hota jaye..
            // aur iske corresspondig store krte rhenge..
            int f =  vec[2];
            // pr increement krne se phle is frequency ke corespond jo dll ka node store hai use erase bhi to 
            // krna pdega..kyuki iski ek nyi frequency aayi hai ab uske corresponding store krenge..
    
            // aur erase kaise krenge..bs us key ke corressponding address hai mp.erase(address) mai daal denge kr dega erase us node ko naaki pure doubly linked list ko
            // yh baat dhyan dene wali hai..
            freq[f].erase(mp[key]);
            
            // erase krne ke baad aisa bhi ho skta hai us dll mai ek hi node tha aur use hi erase krna pda..
            // ab aise mai us freq ya count ke corresponding khuch rhega to hai nhi..
            // to use kyu hi store krke rakhenge..
            // isiliye hume is freq ko erase krna hoga freq map se..
           
            if(freq[f].empty())
               freq.erase(f);  //is frequency mai koi doubly linked list hai hi nhi to erase kr do isko..
    
            // ab krenge frequency ko update..
            f++;
    
            // ab updated frequency ke crossponding ke according ise freq map mai store bhi to krna hai..
            // ab yha pe yh jurrori hai ki push front hi kre kyuki hum recently used ko bhi maintain krna hai..
            // value jo phle upr mai store kr rakha hai..aur key jo ki pass hi hua hai aur updated frequency ke saath dll ko freq map 
            // mai udpate kr denge..
            freq[f].push_front({key,value,f});
    
            // aur ab kyuki ab iska address bhi change ho gya freq map to isko bhi 
            // addressing map mai update krna hoga..
            // aur kyuki push hum humesa front mai hi krte hai to isiliye freq[f].begin() se uska address bhi easily mil jayega..
            // hr cheez ek mtlb se ki gyi hai samjho..
    
            mp[key] = freq[f].begin();
    
            // bs ho gya saara kaam yha ka..
    
        }
    
        int get(int key) {
            // agr key persent hi nhi hai to return -1;
            if(mp.find(key) == mp.end())
             return -1;
            
            // agr key present hai 
            // to key ke sath value doubly linked list ke node mai store kiya ..to wha se lana hoga..
            // waha se laane ke liye ..uske point krna hoga ya uske paas jana hoga..
            // aur uske paas janne ya uske ghar pe jane ke liye uske ghar ka address pta hona chahiye..
            // aur hume key ke corresponding uska address kaha store kra hai..mp wale map..
    
            // so node milega phir node se value nikalenge.. from that address
            // node at that address..which is a vector..
            auto vec = (*(mp[key])); //{key, value, counter}
            //  get the value
             int value =vec[1];
            //  since we have invoked that node or used that node so we have to make it frequently used..
            // let's see how we will do it..
            makeMostFrequentlyUsed(key);
            
            return value;
    
        }
        
        void put(int key, int value) {
            //   agr capacity hi nhi hai to return ho jao..
            if(cap == 0)
              return;
            //   if already persent 
              if(mp.find(key) != mp.end()){
                // point to the node of the linked list
                 auto &vec = (*(mp[key]));
                //  update the value..
                 vec[1] = value;
                // make it most frequently used..
                 makeMostFrequentlyUsed(key);
    
              }
               // agr persent nhi hai aur uske liye jgh bhi khali hai..  
              else if(size <cap){
                // to size ko bdha do..
                size++;
                // aur freq wale map mai dal do aur krenge kha front mai ..to maintain recently used..
                // fresh banda hai..
                freq[1].push_front(vector<int>({key, value, 1}));
                // jo bhi change hoga wh sara ka sara update hota rhega.. dusre map mai bhi.
                mp[key] = freq[1].begin();
              }
            // agr capacity full ho chuki hai to delete krna pdega..
            // as per given condition hume delete kise krna hai jo sbse least frequently used ho..
            // jo ki hum maitain kr rhe ke ordered map ..jo ki hoga uska sbse phla entry..
            // sbse least frequency wala to mil gya ab delete bhi usko krna hai jo most recently wh us count ka.
            // wh hume mil jayega doubly ke back se..hum maintain hi is trah se kr rhe..wh back mai hi hoga..
    
            // yha pe take away yh hai ki hume do cheez maintain krna tha..
            // phla jo frequency maintain krna tha wh ordered map krke kr liye
            // aur dusra jo lru maintain krna tha dll mai front se push krke maintain kr liye..
            // yha pe jis trah fre, lru maintain kiya ja rha hai ..usi trah bhut se chheze bhi maintain kiya ja skta hai.
    
            else{
                // list from which we have to delete the node..
                auto &kaun_sa_list = freq.begin()->second;
                // store the key that we have to deleted bacause we have to remove this key from the mp map also..
                int key_to_deleted = (kaun_sa_list.back())[0];
                // delete the node from the back of the list as a/q to lru concept..
                kaun_sa_list.pop_back();
    
                // maan lo jo delete kiya wh ek hi node tha jo humne phle kiya tha us count ko bhi freq se map se hta denge..
                if(kaun_sa_list.empty()){
                    freq.erase(freq.begin()->first); //map.erase(key)
                }
                // now push the node that is required.
                freq[1].push_front(vector<int>({key, value, 1}));
    
                // ab key ko mp map se delete krke aur jo nya add hua hai wh bhi update krna hoga..to monitor all the changes.
                mp.erase(key_to_deleted);
                // add the address of added value..
                mp[key] = freq[1].begin();
    
            }
    
    
        }
    };
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */