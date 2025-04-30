int findCelebrity(int n) {
    // Write your code here
    // for storing all the people that have arrived in the party..
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    // catch is here that we will take out two person from the party and ask them 
    // that they know each other or not.
    // there can be four possiblites

    // 1.if first person says I know the second person and second says that i dont
    //  know the first person that means that first person can never be the celebrity because as per 
    // the condintion celebrity knows no one..and there is possiblity that second person can be celebrity 
    // so we will send the second person to the party again and hold the first person out the party as we know it is not the 
    // celebrity.

    // 2.if second person says I know the first person and first says that i dont
    //  know the second person that means that second person can never be the celebrity because as per 
    // the condintion celebrity knows no one..and there is possiblity that first person can be celebrity 
    // so we will send the first person back to the party again and now this time hold the second person out the party as we know it is not the 
    // celebrity.

    // 3rd case can be that they can say  that we both know each other and if so that means both of them can't be celebrity 
    // as celebrity knows no one..so both of them will be hold back.

    // 4th case can be that they can say that we both don't know each other that means both of them can't be celebrity as 
    // all the others knows the celebrity..so atleast one of them know the other one..

    // so
    // jb tk party mai ek bhi bnada hai yh upr wale process of asking them krte rhenge..

    while(st.size() > 1){
        // taking out the first person.
        int first = st.top();
        st.pop();
        // taking out the second person.
        int second = st.top();
        st.pop();
        // A/q to first case 
        if(m[first][second] && !m[second][first])
        // possibility second can be celebrity ..so pushed back to the party
        st.push(second);
        // A/q to second case
        if(!m[first][second] && m[second][first])
        // possibility first can be celebrity ..so pushed back to the party
        st.push(first);
        
        // other two cases we don't need to care as per the condition both of them can't be the celebrity..
    }
    // there can be no celebrity in the party in that case stack will be empty and we have to return -1
    if(st.empty())
     return -1;

    //  if there is only one left in the party there is possiblity it can be celebrity but we can't say it for sure.
    // for surity we will double check it with all the others that no one other konws him and he don't know others.
    int num = st.top();
    st.pop();
    int rowsum =0, colsum = n-1;
    for(int i=0;i<n;i++){
        rowsum += m[num][i];
        colsum += m[i][num];
    }
    // he knows no one && all other know him
   if (rowsum ==0 && colsum == n-1){
       return num
   } 
    //no one in the party was celebrity..
   else 
    return -1;
}