double cal(Type a)
 {
     /* ������Ŀ����˼��Ʒ��̼��� */
 }
 
 void Solve(void)
 {
     double Left, Right;
     double mid, midmid;
     double mid_value, midmid_value;
     Left = MIN; Right = MAX;
     while (Left + EPS < Right)
     {
         mid = (Left + Right) / 2;
         midmid = (mid + Right) / 2;
         mid_value = cal(mid);
         midmid_value = cal(midmid);
         // ����������ֵ.
         if (mid_value > midmid_value) Right = midmid;
         else Left = mid;
     }
     return Left; 
 }
