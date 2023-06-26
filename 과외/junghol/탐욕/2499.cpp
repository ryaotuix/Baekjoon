class Solution {
public:

    stack<int> stack;       // stack to actually store ints

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // pointers for each vectors
        int i = 0;      // pushed
        int j = 0;      // popped

        int pushLen = pushed.size();
        int popLen = popped.size();

        while(i < pushLen || j < popLen)
        {
            // if we all pushed
            if (i == pushLen)
            {
                // pushed all, but have to pop -> false
                if (stack.empty())
                    return false;
                
                // can pop 1. pop 2. j++ 3. continue
                if (stack.top() == popped[j])
                {
                    stack.pop();
                    j++;
                    continue;
                }
                // cannot pop when we have to
                else
                    return false;
            }

            // if we didn't push all
            else
            {
                // if empty, push, i++, continue
                if (stack.empty())
                {
                    stack.push(pushed[i]);
                    i++;
                    continue;
                }

                // if top == j -> pop, j++, continue
                if (stack.top() == popped[j])
                {
                    stack.pop();
                    j++;
                    continue;
                }
                else
                {
                    stack.push(pushed[i]);
                    i++;
                }
            }
        }

        return true;
    }
};