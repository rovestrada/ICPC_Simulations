#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long double ld;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for (ll i = (a), TT = (b); i < TT; ++i)

#define INF LLONG_MAX / 3

ll n;
ll len = 4;
ll moves = INF;
vector<bool> chosen(len);

ll lengthOfLIS(vector<ll> &nums)
{
    ll n = nums.size();
    vector<ll> ans;

    if (n == 0)
        return 0;

    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            ll low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); //<=
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

void search(vector<pair<char, ll>> &cards)
{
    string swerc = "SWER";

    do
    {
        map<char, ll> card_value;
        vector<ll> new_cards(n);
        fore(i, 0, 4)
        {
            card_value.insert({swerc[i], i});
        }
        card_value.insert({'C', 4});

        fore(i, 0, n)
        {
            char suit = cards[i].first;
            ll num = cards[i].second;
            new_cards[i] = card_value[suit] * 1000000 + num;
            // cout << cards[i].first << cards[i].second << ":" << new_cards[i] << " ";
        }
        // cout << endl;

        // ll lis = lengthOfLIS(new_cards);
        // print("lis: " << lis);
        // print("moves: " << n - lis);

        moves = min(moves, n - lengthOfLIS(new_cards));
    } while (next_permutation(swerc.begin(), swerc.end()));
}

int main()
{
    FIN;
    cin >> n;
    vector<pair<char, ll>> cards(n);

    fore(i, 0, n)
    {
        string s;
        cin >> s;
        char suit = s[0];
        ll num = stoll(s.substr(1));
        cards[i] = {suit, num};
    }

    search(cards);
    print(moves);
}