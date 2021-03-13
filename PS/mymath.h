#pragma once
unsigned long long gcd(unsigned long long u, unsigned long long v) {
    if (v == 0) {
        return u;
    }
    else {
        return gcd(v, u % v);
    }
}

//���� a�� mod �� ���μҶ�� %mod���꿡 ���� a�� ������ a^(mod-2) �̴�.
long long binpow(long long val, long long deg, long long mod) {
    if (!deg) return 1 % mod;
    if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val, deg >> 1, mod);
    return (res * res) % mod;
}
