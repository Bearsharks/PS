#pragma once
#include <random>
typedef long long ll;
typedef unsigned long long ull;
ull gcd(ull u, ull v) {
    if (v == 0) {
        return u;
    }
    else {
        return gcd(v, u % v);
    }
}

//���� a�� mod �� ���μҶ�� %mod���꿡 ���� a�� ������ a^(mod-2) �̴�.
ll binpow(ll val, ll deg, ll mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    ll res = binpow(val, deg >> 1, mod);
    return (res * res) % mod;
}

ull llpow(ull val, ull deg) {
    if (!deg) return 1;
    if (deg & 1) return llpow(val, deg - 1) * val;
    ull res = llpow(val, deg >> 1);
    return res * res;
}
