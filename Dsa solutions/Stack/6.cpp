// 84. Largest Rectangle in Histogram

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
int largestRectangleArea(vector<int>& heights) {
        vector<int> sl = nsol(heights);
    vector<int> sr = nsor(heights);

    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int w = sr[i] - sl[i] - 1;
        int h = heights[i];

        area = max(area, w * h);
    }

    return area;
}

// 2nd method 
    int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0)
        return 0;

    stack<int> st;
    st.push(-1);
    int area = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (st.top() != -1 && heights[i] <= heights[st.top()])
        {
            int h = heights[st.top()];
            st.pop();
            int w = i - st.top() - 1;

            area = max(area, h * w);
        }
        st.push(i);
    }

    while (st.top() != -1)
    {
        int h = heights[st.top()];
        st.pop();
        int w = n - st.top() - 1;

        area = max(area, h * w);
    }
    return area;
    }