/*At a lemonade stand, each lemonade costs $5. Customers are standing ,
in a queue to buy from you and order one at a time (in the order specified by bills).
 Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
 You must provide the correct change to each customer so that the net transaction is ,
 that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays,
 return true if you can provide every customer with the correct change, or false otherwise.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      unordered_map<int,long long>notes;
      for(int i=0;i<bills.size();i++)
      {
          cout<<notes[5]<<","<<notes[10]<<","<<notes[20]<<endl;
          if(bills[i]==5)
          {
              notes[5]++;
              continue;
          }
          else if(bills[i]==10)
          {
              if(notes[5]>0)
              {
                  notes[5]--;
                  notes[bills[i]]++;
                  continue;
              }
              else
              {
                  return false;
              }
          }
          else
          {
              if((notes[5]>=3 )||(notes[5]>=1 && notes[10]>=1))
              {
                  if(notes[5]>0 && notes[10])
                  {
                      notes[bills[i]]++;
                      notes[5]--;
                      notes[10]--;
                      continue;
                  }
                 else if(notes[5]>=3)
                  {
                      notes[bills[i]]++;
                      notes[5]=notes[5]-3;
                      continue;
                  }

              }
              else
              {
                  return false;
              }

          }
      }
      return true;
    }
};