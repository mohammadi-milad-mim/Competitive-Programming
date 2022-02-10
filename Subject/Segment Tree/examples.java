public class examples {
    ////////////////////////////////////////////////////
  //              Example usage:                    //
  ////////////////////////////////////////////////////

  public static void main(String[] args) {
    t();
    // sumQuerySumUpdateExample();
    // minQueryAssignUpdateExample();
    // gcdQueryMulUpdateExample();
    // gcdQueryAssignUpdateExample();
    // productQueryMulUpdateExample();
  }

  private static void productQueryMulUpdateExample() {
    //        0, 1, 2, 3
    long[] v = {3, 2, 2, 1};
    GenericSegmentTree st =
        new GenericSegmentTree(v, SegmentCombinationFn.PRODUCT, RangeUpdateFn.MULTIPLICATION);

    int l = 0;
    int r = 3;
    long q = st.rangeQuery1(l, r);
    if (q != 12) System.out.println("Error");
    System.out.printf("The product between indeces [%d, %d] is: %d\n", l, r, q);

    // 3, 8, 8, 1
    // 3 * 8 * 8 * 1 = 192
    st.rangeUpdate1(1, 2, 4);
    q = st.rangeQuery1(l, r);
    if (q != 192) System.out.println("Error");
    System.out.printf("The product between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));

    // 3, 8, 16, 2
    // 3 * 8 * 16 * 2 = 768
    st.rangeUpdate1(2, 3, 2);
    q = st.rangeQuery1(l, r);
    if (q != 768) System.out.println("Error");
    System.out.printf("The product between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));

    // 12, 24, 24, 24, 48
    // st.rangeUpdate1(2, 3, 24);
    // l = 0;
    // r = 4;
    // q = st.rangeQuery1(l, r);
    // if (q != 12) System.out.println("Error");
    // System.out.printf("The product between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l,
    // r));
  }

  private static void gcdQueryMulUpdateExample() {
    //           0,  1, 2, 3,  4
    long[] v = {12, 24, 3, 4, -1};
    GenericSegmentTree st =
        new GenericSegmentTree(v, SegmentCombinationFn.GCD, RangeUpdateFn.MULTIPLICATION);

    int l = 0;
    int r = 2;
    long q = st.rangeQuery1(l, r);
    if (q != 3) System.out.println("Error");
    System.out.printf("The gcd between indeces [%d, %d] is: %d\n", l, r, q);
    st.rangeUpdate1(2, 2, 2);
    q = st.rangeQuery1(l, r);
    if (q != 6) System.out.println("Error");
    System.out.printf("The gcd between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));

    r = 1; // [l, r] = [0, 1]
    q = st.rangeQuery1(l, r);
    if (q != 12) System.out.println("Error");
    System.out.printf("The gcd between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));
  }

  private static void gcdQueryAssignUpdateExample() {
    //           0,  1, 2, 3,  4
    long[] v = {12, 24, 3, 12, 48};
    GenericSegmentTree st =
        new GenericSegmentTree(v, SegmentCombinationFn.GCD, RangeUpdateFn.ASSIGN);

    int l = 0;
    int r = 2;
    long q = st.rangeQuery1(l, r);
    if (q != 3) System.out.println("Error");
    System.out.printf("The gcd between indeces [%d, %d] is: %d\n", l, r, q);

    // 12, 24, 48, 12, 48
    st.rangeUpdate1(2, 2, 48);
    q = st.rangeQuery1(l, r);
    if (q != 12) System.out.println("Error");
    System.out.printf("The gcd between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));

    // 12, 24, 24, 24, 48
    st.rangeUpdate1(2, 3, 24);
    l = 0;
    r = 4;
    q = st.rangeQuery1(l, r);
    if (q != 12) System.out.println("Error");
    System.out.printf("The gcd between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));
  }

  private static void sumQuerySumUpdateExample() {
    //          0, 1, 2, 3,  4
    long[] v = {2, 1, 3, 4, -1};
    GenericSegmentTree st =
        new GenericSegmentTree(v, SegmentCombinationFn.SUM, RangeUpdateFn.ADDITION);

    int l = 1;
    int r = 3;
    long q = st.rangeQuery1(l, r);
    if (q != 8) System.out.println("Error");
    System.out.printf("The sum between indeces [%d, %d] is: %d\n", l, r, q);
    st.rangeUpdate1(1, 3, 3);
    q = st.rangeQuery1(l, r);
    if (q != 17) System.out.println("Error");
    System.out.printf("The sum between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));
  }

  private static void t() {
    long[] v = {1, 4, 3, 0, 5, 8, -2, 7, 5, 2, 9};
    GenericSegmentTree st =
        new GenericSegmentTree(v, SegmentCombinationFn.MIN, RangeUpdateFn.ASSIGN);
    st.printDebugInfo();
  }

  private static void minQueryAssignUpdateExample() {
    //          0, 1, 2, 3,  4
    long[] v = {2, 1, 3, 4, -1};
    GenericSegmentTree st =
        new GenericSegmentTree(v, SegmentCombinationFn.MIN, RangeUpdateFn.ASSIGN);

    // System.out.println(java.util.Arrays.toString(st.t));

    int l = 1;
    int r = 3;
    long q = st.rangeQuery1(l, r);
    if (q != 1) System.out.println("Error");
    System.out.printf("The min between indeces [%d, %d] is: %d\n", l, r, q);
    st.rangeUpdate1(1, 3, 3);
    l = 0;
    r = 1;
    q = st.rangeQuery1(l, r);
    if (q != 2) System.out.println("Error");
    System.out.printf("The min between indeces [%d, %d] is: %d\n", l, r, st.rangeQuery1(l, r));
  }
}
}
