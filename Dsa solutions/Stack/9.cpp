// 735 Asteroid Collision

vector<int> asteroidCollision(vector<int> &arr)
{
    stack<int> st;
    for (int ele : arr)
    {

        if (ele > 0)
        {
            st.push(ele);
            continue;
        }

        while (st.size() != 0 && st.top() > 0 && st.top() < -ele)
            st.pop();

        if (st.size() != 0 && st.top() == -ele)
            st.pop();
        else if (st.size() == 0 || st.top() < 0)
            st.push(ele);
        else
        {
            // do Nothing.
        }
    }

    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}
