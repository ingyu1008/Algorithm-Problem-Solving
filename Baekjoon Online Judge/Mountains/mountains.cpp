#include "mountains.h"
#include <vector>

typedef long long ll;

typedef std::pair<ll, ll> vec;

int ccw(vec a, vec b)
{
	ll res = a.first * b.second - a.second * b.first;
	if (res > 0)
	{
		return 1;
	}
	else if (res < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int ccw_point(vec a, vec b, vec c)
{
	vec ab = {b.first - a.first, b.second - a.second};
	vec bc = {c.first - b.first, c.second - b.second};

	return ccw(ab, bc);
}

ll dp[2020][2020];

int maximum_deevs(std::vector<int> y)
{
	for (int i = 0; i < 2020; i++)
	{
		for (int j = 0; j < 2020; j++)
		{
			dp[i][j] = 0;
		}
	}
	std::vector<vec> v(y.size() + 1);
	for (int i = 0; i < y.size(); i++)
	{
		v[i + 1] = {i + 1, y[i]};
	}

	for (int i = 1; i < v.size(); i++)
	{
		dp[i][i] = dp[i - 1][i] = 1;
		ll x = i - 1;
		ll cnt = 1;
		for (int j = i - 2; j >= 1; j--)
		{
			if (ccw_point(v[j], v[x], v[i]) >= 0)
			{
				cnt += dp[j + 1][x - 1];
				x = j;
			}
			dp[j][i] = std::max(dp[j][i - 1], dp[j][x - 1] + cnt);
		}
	}

	return dp[1][y.size()];
}
