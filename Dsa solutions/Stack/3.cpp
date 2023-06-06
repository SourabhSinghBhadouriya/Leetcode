// next greater on right

vector<int> ngor(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);

    int n = arr.size();
    vector<int> ans(n, n);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

// next greater on left
vector<int> ngol(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);

    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

//  next smallest on right
vector<int> nsor(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);

    int n = arr.size();
    vector<int> ans(n, n);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

// next greater on left
vector<int> nsol(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);

    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] > arr[i])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

// Next Greater Element(GFG)

vector<long long> nextLargerElement(vector<long long> &arr, int n){
    stack<int> st;
    st.push(-1);
    vector<long long> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
    }

//Leetcode 503 Next Greater Element II

vector<int> nextGreaterElements(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);

    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < 2 * n; i++)
    {
        while (st.top() != -1 && arr[st.top()] < arr[i % n])
        {
            ans[st.top()] = arr[i % n];
            st.pop();
        }
        if (i < n)
            st.push(i);
    }

    return ans;
}
