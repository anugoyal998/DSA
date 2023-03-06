const ll MAXM = 1e5;
vector<ll> factors[MAXM + 5];

void init()
{
    for (ll i = 1; i <= MAXM; i++)
    {
        for (ll j = i; j <= MAXM; j += i)
        {
            factors[j].pb(i);
        }
    }
}