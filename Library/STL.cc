using namespace __gnu_cxx;
struct myhash{
    inline unsigned LL operator() (pair<int, int> a) const {
        return a.first * 1234567891ULL + a.second;
    }
};
hash_map<pair<int, int>, int, myhash> mp;

bitset<1000> now;
now.all(); now.any(); now.none(); now.count();
now.flip(); now.flip(2); now.test(2);
now.set(); now.set(2); now.set(2, 0); now.reset(); now.reset(2);
now.to_string(); now.to_ullong();

//a[5] is the 6th 
nth_element(a.begin(), a.begin() + 6, a.end())
nth_element(a.begin(), a.begin() + 6, a.end(), cmp)



