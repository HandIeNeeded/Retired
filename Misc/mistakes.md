##Mistakes

+ CF696 
  + vector<LL> 开成 vector<int>
  + 需要无穷小, 又涉及加法, 设置成LLONG_MIN越界了, 应该设置成相加不会越界的.
