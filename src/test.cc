#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(Constructor, DefaultConstructor) {
  S21Matrix firstMatrix;
  EXPECT_EQ(firstMatrix.GetRows(), 1);
  EXPECT_EQ(firstMatrix.GetColumns(), 1);
}

TEST(Constructor, Constructor_1) {
  int rows = 3;
  int columns = 4;
  S21Matrix sample(rows, columns);
  EXPECT_EQ(sample.GetRows(), rows);
  EXPECT_EQ(sample.GetColumns(), columns);
}

TEST(Constructor, Constructor_Copy) {
  int rows = 3;
  int columns = 4;
  S21Matrix sample(rows, columns);
  S21Matrix expect(sample);
  EXPECT_EQ(sample.EqMatrix(expect), 1);
}

TEST(Constructors, Copy) {
  S21Matrix source(3, 3);
  source(0, 0) = 99;
  source(2, 2) = -99;
  source(1, 1) = 13;
  S21Matrix copy(source);
  ASSERT_EQ(source.EqMatrix(copy), 1);
}

TEST(Constructors, Allocate) {
  auto source = new S21Matrix;
  delete source;
}

TEST(Complements, S1) {
  S21Matrix source(3, 3);
  S21Matrix expected(3, 3);
  source(0, 0) = 1;
  source(0, 1) = 2;
  source(0, 2) = 3;
  source(1, 0) = 0;
  source(1, 1) = 4;
  source(1, 2) = 2;
  source(2, 0) = 5;
  source(2, 1) = 2;
  source(2, 2) = 1;
  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;
  S21Matrix result = source.CalcComplements();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Complements, S2) {
  S21Matrix source(3, 3);
  S21Matrix expected(3, 3);
  source(0, 0) = 1.0;
  source(0, 1) = 2.0;
  source(0, 2) = 3.0;
  source(1, 0) = 0.0;
  source(1, 1) = 4.0;
  source(1, 2) = 2.0;
  source(2, 0) = 5.0;
  source(2, 1) = 2.0;
  source(2, 2) = 1.0;
  expected(0, 0) = 0.0;
  expected(0, 1) = 10.0;
  expected(0, 2) = -20.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = -14.0;
  expected(1, 2) = 8.0;
  expected(2, 0) = -8.0;
  expected(2, 1) = -2.0;
  expected(2, 2) = 4.0;
  S21Matrix result = source.CalcComplements();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Complements, BigMatrix) {
  S21Matrix source(9, 9);
  S21Matrix expected(9, 9);
  source(0, 0) = 43.12901;
  source(0, 1) = 55.63335;
  source(0, 2) = 93.05234;
  source(0, 3) = 65.39499;
  source(0, 4) = 5.10401;
  source(0, 5) = 16.76916;
  source(0, 6) = 28.60075;
  source(0, 7) = 54.90999;
  source(0, 8) = 19.59398;
  source(1, 0) = 56.05809;
  source(1, 1) = 79.39113;
  source(1, 2) = 66.70486;
  source(1, 3) = 53.75779;
  source(1, 4) = 36.12673;
  source(1, 5) = 94.47841;
  source(1, 6) = 2.49919;
  source(1, 7) = 36.62309;
  source(1, 8) = 87.75020;
  source(2, 0) = 59.13214;
  source(2, 1) = 40.77826;
  source(2, 2) = 61.40607;
  source(2, 3) = 6.77803;
  source(2, 4) = 13.51012;
  source(2, 5) = 8.41554;
  source(2, 6) = 64.03128;
  source(2, 7) = 41.04432;
  source(2, 8) = 84.68183;
  source(3, 0) = 88.13066;
  source(3, 1) = 58.85910;
  source(3, 2) = 5.25260;
  source(3, 3) = 9.06739;
  source(3, 4) = 35.24944;
  source(3, 5) = 2.09267;
  source(3, 6) = 62.90898;
  source(3, 7) = 69.96831;
  source(3, 8) = 46.83367;
  source(4, 0) = 50.90437;
  source(4, 1) = 93.22886;
  source(4, 2) = 59.31649;
  source(4, 3) = 77.31154;
  source(4, 4) = 89.95462;
  source(4, 5) = 92.11142;
  source(4, 6) = 11.90333;
  source(4, 7) = 96.46219;
  source(4, 8) = 32.30722;
  source(5, 0) = 18.81537;
  source(5, 1) = 92.96907;
  source(5, 2) = 58.40735;
  source(5, 3) = 92.76283;
  source(5, 4) = 32.97185;
  source(5, 5) = 35.62629;
  source(5, 6) = 85.00595;
  source(5, 7) = 20.45652;
  source(5, 8) = 50.67907;
  source(6, 0) = 49.05100;
  source(6, 1) = 47.30376;
  source(6, 2) = 50.59537;
  source(6, 3) = 56.91111;
  source(6, 4) = 19.38206;
  source(6, 5) = 80.31103;
  source(6, 6) = 16.37007;
  source(6, 7) = 47.62688;
  source(6, 8) = 53.01047;
  source(7, 0) = 44.35928;
  source(7, 1) = 59.64963;
  source(7, 2) = 54.51389;
  source(7, 3) = 28.63571;
  source(7, 4) = 23.66667;
  source(7, 5) = 6.49841;
  source(7, 6) = 30.65270;
  source(7, 7) = 76.62214;
  source(7, 8) = 76.33952;
  source(8, 0) = 4.06320;
  source(8, 1) = 37.13978;
  source(8, 2) = 18.34000;
  source(8, 3) = 84.54349;
  source(8, 4) = 4.51523;
  source(8, 5) = 23.35041;
  source(8, 6) = 53.08836;
  source(8, 7) = 59.12912;
  source(8, 8) = 98.28393;

  expected(0, 0) = 352094054087773.000000;
  expected(0, 1) = -275452031583077.218750;
  expected(0, 2) = 110729441406593.625000;
  expected(0, 3) = 397930918620282.000000;
  expected(0, 4) = 233951474212390.125000;
  expected(0, 5) = -314748435262032.750000;
  expected(0, 6) = -214751950078658.093750;
  expected(0, 7) = -208438743341274.468750;
  expected(0, 8) = 32000565077014.066406;
  expected(1, 0) = 369935382851228.437500;
  expected(1, 1) = -128614561920689.062500;
  expected(1, 2) = -10626881806222.177734;
  expected(1, 3) = 352725922463457.250000;
  expected(1, 4) = 337922244423796.312500;
  expected(1, 5) = -314450864521521.250000;
  expected(1, 6) = -353566670873179.500000;
  expected(1, 7) = -391096561146772.250000;
  expected(1, 8) = 217329951696271.375000;
  expected(2, 0) = 112326540066266.515625;
  expected(2, 1) = -426756176012921.437500;
  expected(2, 2) = 193788164652257.437500;
  expected(2, 3) = 62713701354528.296875;
  expected(2, 4) = 395320397541603.437500;
  expected(2, 5) = -78397420762721.156250;
  expected(2, 6) = 90061125022729.265625;
  expected(2, 7) = -159415307669893.656250;
  expected(2, 8) = 114236925600254.593750;
  expected(3, 0) = 283333462807393.312500;
  expected(3, 1) = -20538022093429.445312;
  expected(3, 2) = -136299524245782.468750;
  expected(3, 3) = 169112797052264.031250;
  expected(3, 4) = 61873854811187.257812;
  expected(3, 5) = -140854245387040.125000;
  expected(3, 6) = -76606470499929.078125;
  expected(3, 7) = -97342023956684.671875;
  expected(3, 8) = 6574565126667.367188;
  expected(4, 0) = 52046738243277.335938;
  expected(4, 1) = -255309696985477.625000;
  expected(4, 2) = 68768851813273.414062;
  expected(4, 3) = 127391745816806.328125;
  expected(4, 4) = 388278066831111.500000;
  expected(4, 5) = -87547825599791.125000;
  expected(4, 6) = -34560807081993.523438;
  expected(4, 7) = -50311417729885.796875;
  expected(4, 8) = 23809237293643.117188;
  expected(5, 0) = -253966526363537.343750;
  expected(5, 1) = 338765496394124.750000;
  expected(5, 2) = -35743431617787.039062;
  expected(5, 3) = -219791000213532.625000;
  expected(5, 4) = -253461079910985.250000;
  expected(5, 5) = 177086379866762.781250;
  expected(5, 6) = 197381254623831.281250;
  expected(5, 7) = 84350376389676.453125;
  expected(5, 8) = -109571743692029.812500;
  expected(6, 0) = -489628418893748.250000;
  expected(6, 1) = 439417845516568.937500;
  expected(6, 2) = -76251673903666.906250;
  expected(6, 3) = -616798258746881.625000;
  expected(6, 4) = -853525603482564.625000;
  expected(6, 5) = 699228961747087.875000;
  expected(6, 6) = 433146054187475.375000;
  expected(6, 7) = 547230619941843.625000;
  expected(6, 8) = -291109522998202.875000;
  expected(7, 0) = -611928392466076.750000;
  expected(7, 1) = 735661215619490.875000;
  expected(7, 2) = -58229144363223.718750;
  expected(7, 3) = -658584820985793.250000;
  expected(7, 4) = -727031826586246.750000;
  expected(7, 5) = 362156100417640.750000;
  expected(7, 6) = 178006032394272.125000;
  expected(7, 7) = 534560445265623.875000;
  expected(7, 8) = -145708877160955.312500;
  expected(8, 0) = 220958439055376.250000;
  expected(8, 1) = -351941811137638.500000;
  expected(8, 2) = -32426597928385.417969;
  expected(8, 3) = 386800165629530.812500;
  expected(8, 4) = 309684619972237.812500;
  expected(8, 5) = -242802316191517.656250;
  expected(8, 6) = -144907646911019.562500;
  expected(8, 7) = -162844592332900.125000;
  expected(8, 8) = 170959697495350.125000;
  S21Matrix result = source.CalcComplements();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Complements, 2dMatrix) {
  S21Matrix source(2, 2), expected(2, 2);
  source(0, 0) = 3;
  source(0, 1) = 1;
  source(1, 0) = 20;
  source(1, 1) = -2;
  expected(0, 0) = -2;
  expected(0, 1) = -20;
  expected(1, 0) = -1;
  expected(1, 1) = 3;
  S21Matrix result = source.CalcComplements();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Determinant, JContent) {
  int size = 5;
  S21Matrix source(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      source(i, j) = j;
    }
  }
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, 0);
}

TEST(Determinant, IJContent) {
  int size = 5;
  S21Matrix source(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      source(i, j) = i + j;
    }
  }
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, 0);
}

TEST(Determinant, 3dSimple) {
  int size = 3;
  S21Matrix source(size, size);
  source(0, 0) = 2;
  source(0, 1) = 3;
  source(0, 2) = 1;
  source(1, 0) = 7;
  source(1, 1) = 4;
  source(1, 2) = 1;
  source(2, 0) = 9;
  source(2, 1) = -2;
  source(2, 2) = 1;
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, -32);
}

TEST(Determinant, 2dSimple) {
  int size = 2;
  S21Matrix source(size, size);
  source(0, 0) = -5;
  source(0, 1) = -4;
  source(1, 0) = -2;
  source(1, 1) = -3;
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, 7);
}

TEST(Determinant, 8dSimple) {
  int size = 8;
  S21Matrix source(size, size);
  source(0, 0) = 2;
  source(0, 1) = 8;
  source(0, 2) = 7;
  source(0, 3) = 4;
  source(0, 4) = 1;
  source(0, 5) = 8;
  source(0, 6) = 3;
  source(0, 7) = 9;
  source(1, 0) = 4;
  source(1, 1) = 2;
  source(1, 2) = 6;
  source(1, 3) = 2;
  source(1, 4) = 2;
  source(1, 5) = 1;
  source(1, 6) = 5;
  source(1, 7) = 8;
  source(2, 0) = 8;
  source(2, 1) = 6;
  source(2, 2) = 7;
  source(2, 3) = 7;
  source(2, 4) = 3;
  source(2, 5) = 4;
  source(2, 6) = 4;
  source(2, 7) = 1;
  source(3, 0) = 1;
  source(3, 1) = 7;
  source(3, 2) = 0;
  source(3, 3) = 4;
  source(3, 4) = 4;
  source(3, 5) = 3;
  source(3, 6) = 0;
  source(3, 7) = 5;
  source(4, 0) = 5;
  source(4, 1) = 7;
  source(4, 2) = 5;
  source(4, 3) = 6;
  source(4, 4) = 8;
  source(4, 5) = 3;
  source(4, 6) = 1;
  source(4, 7) = 9;
  source(5, 0) = 3;
  source(5, 1) = 7;
  source(5, 2) = 8;
  source(5, 3) = 0;
  source(5, 4) = 5;
  source(5, 5) = 7;
  source(5, 6) = 0;
  source(5, 7) = 2;
  source(6, 0) = 5;
  source(6, 1) = 8;
  source(6, 2) = 3;
  source(6, 3) = 5;
  source(6, 4) = 9;
  source(6, 5) = 1;
  source(6, 6) = 2;
  source(6, 7) = 0;
  source(7, 0) = 7;
  source(7, 1) = 8;
  source(7, 2) = 7;
  source(7, 3) = 4;
  source(7, 4) = 7;
  source(7, 5) = 9;
  source(7, 6) = 1;
  source(7, 7) = 5;
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, -616458);
}

TEST(Determinant, 1dSimple) {
  S21Matrix source(1, 1);
  source(0, 0) = 9;
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, 9);
}

TEST(Determinant, AllZero) {
  S21Matrix source(15, 15);
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, 0);
}

TEST(Determinant, 2dMatrix) {
  S21Matrix source(2, 2);
  source(0, 0) = 73;
  source(0, 1) = 16;
  source(1, 0) = 0;
  source(1, 1) = -4;
  double result = source.Determinant();
  ASSERT_DOUBLE_EQ(result, -292);
}

TEST(EqMatrix, JEqual) {
  int size = 5;
  S21Matrix a(size, size), b(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = b(i, j) = j;
    }
  }
  ASSERT_EQ(a.EqMatrix(b), 1);
  ASSERT_EQ(b.EqMatrix(a), 1);
}

TEST(EqMatrix, IJEqual) {
  int size = 5;
  S21Matrix a(size, size), b(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = b(i, j) = i + j;
    }
  }
  ASSERT_EQ(a.EqMatrix(b), 1);
  ASSERT_EQ(b.EqMatrix(a), 1);
}

TEST(EqMatrix, IJDivEqual) {
  int size = 5;
  S21Matrix a(size, size), b(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = b(i, j) = (i + j) / 3;
    }
  }
  ASSERT_EQ(a.EqMatrix(b), 1);
  ASSERT_EQ(b.EqMatrix(a), 1);
}

TEST(EqMatrix, NotEqual) {
  int size = 5;
  S21Matrix a(size, size), b(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = i + j;
      b(i, j) = i + j + 1;
    }
  }
  ASSERT_EQ(a.EqMatrix(b), 0);
  ASSERT_EQ(b.EqMatrix(a), 0);
}

TEST(EqMatrix, PrecisionTest) {
  int size = 5;
  S21Matrix a(size, size), b(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = b(i, j) = (i + j) / 3;
    }
  }
  a(4, 3) -= 0.000002;
  ASSERT_EQ(a.EqMatrix(b), 0);
  ASSERT_EQ(b.EqMatrix(a), 0);
}

TEST(EqMatrix, OverPrecisionTest) {
  int size = 5;
  S21Matrix a(size, size), b(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = b(i, j) = (i + j) / 3;
    }
  }
  a(4, 3) -= 0.0000001;
  ASSERT_EQ(a.EqMatrix(b), 1);
  ASSERT_EQ(b.EqMatrix(a), 1);
}

TEST(EqMatrix, DiffDimension) {
  int size = 4;
  S21Matrix a(size, size), b(size - 1, size - 1);
  ASSERT_EQ(a.EqMatrix(b), 0);
  ASSERT_EQ(b.EqMatrix(a), 0);
}

TEST(EqMatrix, EmptyMatrices) {
  int size = 9;
  S21Matrix a(size, size), b(size, size);
  ASSERT_EQ(a.EqMatrix(b), 1);
  ASSERT_EQ(b.EqMatrix(a), 1);
}

TEST(EqMatrix, Uninitialized) {
  S21Matrix a, b;
  ASSERT_EQ(a.EqMatrix(b), 1);
  ASSERT_EQ(b.EqMatrix(a), 1);
}

TEST(MulNumber, 1dMatrix) {
  S21Matrix source;
  source(0, 0) = 3.141592;
  source.MulNumber(2.718281);
  S21Matrix expected;
  expected(0, 0) = 8.53973;
  ASSERT_EQ(source.EqMatrix(expected), 1);
}

TEST(MulNumber, 3dMatrix) {
  S21Matrix source(3, 3);
  source(0, 0) = 1.3;
  source(1, 0) = 89.13;
  source(2, 0) = 1;
  source(0, 1) = 9.1;
  source(1, 1) = 7;
  source(2, 1) = 1389;
  source(0, 2) = 8.123;
  source(1, 2) = 0;
  source(2, 2) = 0.0004;
  source.MulNumber(1.234567);
  S21Matrix expected(3, 3);
  expected(0, 0) = 1.3 * 1.234567;
  expected(1, 0) = 89.13 * 1.234567;
  expected(2, 0) = 1 * 1.234567;
  expected(0, 1) = 9.1 * 1.234567;
  expected(1, 1) = 7 * 1.234567;
  expected(2, 1) = 1389 * 1.234567;
  expected(0, 2) = 8.123 * 1.234567;
  expected(1, 2) = 0 * 1.234567;
  expected(2, 2) = 0.0004 * 1.234567;
  ASSERT_EQ(source.EqMatrix(expected), 1);
}

TEST(Mutators, Setter1) {
  int size = 9;
  S21Matrix source(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      source(i, j) = i + j;
    }
  }
  size--;
  source.SetRows(size);
  ASSERT_EQ(source.GetRows(), size);
}

TEST(Mutators, Setter2) {
  int size = 9;
  S21Matrix source(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      source(i, j) = i + j;
    }
  }
  size++;
  source.SetRows(size);
  ASSERT_EQ(source.GetRows(), size);
  ASSERT_DOUBLE_EQ(source(size - 1, size - 2), 0);
}

TEST(Mutators, Setter3) {
  int size = 9;
  S21Matrix source(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      source(i, j) = i + j;
    }
  }
  size--;
  source.SetColumns(size);
  ASSERT_EQ(source.GetColumns(), size);
}

TEST(Mutators, Setter4) {
  int size = 9;
  S21Matrix source(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      source(i, j) = i + j;
    }
  }
  size++;
  source.SetColumns(size);
  ASSERT_EQ(source.GetColumns(), size);
  ASSERT_DOUBLE_EQ(source(size - 2, size - 1), 0);
}

TEST(Overload, Sum) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 352.412;
  source1(1, 0) = 1;
  source1(2, 0) = 1;
  source1(0, 1) = 1234.8234;
  source1(1, 1) = 0.00001;
  source1(2, 1) = 352.412;
  source1(0, 2) = 1234.8234;
  source1(1, 2) = 352.412;
  source1(2, 2) = 9;

  source2(0, 0) = 352.412;
  source2(1, 0) = 1;
  source2(2, 0) = 0;
  source2(0, 1) = -1234.8234;
  source2(1, 1) = 0.00001;
  source2(2, 1) = 123456789;
  source2(0, 2) = -0.00001;
  source2(1, 2) = 0.412;
  source2(2, 2) = 9;
  S21Matrix result = source1 + source2;
  expected(0, 0) = 352.412 + 352.412;
  expected(1, 0) = 1 + 1;
  expected(2, 0) = 1;
  expected(0, 1) = -1234.8234 + 1234.8234;
  expected(1, 1) = 0.00001 + 0.00001;
  expected(2, 1) = 352.412 + 123456789;
  expected(0, 2) = -0.00001 + 1234.8234;
  expected(1, 2) = 352.412 + 0.412;
  expected(2, 2) = 9 + 9;
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Overload, Sub) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 352.412;
  source1(1, 0) = 1;
  source1(2, 0) = 1;
  source1(0, 1) = 1234.8234;
  source1(1, 1) = 0.00001;
  source1(2, 1) = 352.412;
  source1(0, 2) = 1234.8234;
  source1(1, 2) = 352.412;
  source1(2, 2) = 9;

  source2(0, 0) = 352.412;
  source2(1, 0) = 1;
  source2(2, 0) = 0;
  source2(0, 1) = -1234.8234;
  source2(1, 1) = 0.00001;
  source2(2, 1) = 123456789;
  source2(0, 2) = -0.00001;
  source2(1, 2) = 0.412;
  source2(2, 2) = 9;
  S21Matrix result = source1 - source2;
  expected(0, 0) = 352.412 - 352.412;
  expected(1, 0) = 0;
  expected(2, 0) = 1;
  expected(0, 1) = 1234.8234 - -1234.8234;
  expected(1, 1) = 0.00001 - 0.00001;
  expected(2, 1) = 352.412 - 123456789;
  expected(0, 2) = 1234.8234 - -0.00001;
  expected(1, 2) = 352.412 - 0.412;
  expected(2, 2) = 0;
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Overload, MulNum1) {
  S21Matrix source(3, 3);
  source(0, 0) = 1.3;
  source(1, 0) = 89.13;
  source(2, 0) = 1;
  source(0, 1) = 9.1;
  source(1, 1) = 7;
  source(2, 1) = 1389;
  source(0, 2) = 8.123;
  source(1, 2) = 0;
  source(2, 2) = 0.0004;
  S21Matrix result = source * 1.234567;
  S21Matrix expected(3, 3);
  expected(0, 0) = 1.3 * 1.234567;
  expected(1, 0) = 89.13 * 1.234567;
  expected(2, 0) = 1 * 1.234567;
  expected(0, 1) = 9.1 * 1.234567;
  expected(1, 1) = 7 * 1.234567;
  expected(2, 1) = 1389 * 1.234567;
  expected(0, 2) = 8.123 * 1.234567;
  expected(1, 2) = 0 * 1.234567;
  expected(2, 2) = 0.0004 * 1.234567;
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Overload, MulNum2) {
  S21Matrix source(3, 3);
  source(0, 0) = 1.3;
  source(1, 0) = 89.13;
  source(2, 0) = 1;
  source(0, 1) = 9.1;
  source(1, 1) = 7;
  source(2, 1) = 1389;
  source(0, 2) = 8.123;
  source(1, 2) = 0;
  source(2, 2) = 0.0004;
  S21Matrix result = 1.234567 * source;
  S21Matrix expected(3, 3);
  expected(0, 0) = 1.3 * 1.234567;
  expected(1, 0) = 89.13 * 1.234567;
  expected(2, 0) = 1 * 1.234567;
  expected(0, 1) = 9.1 * 1.234567;
  expected(1, 1) = 7 * 1.234567;
  expected(2, 1) = 1389 * 1.234567;
  expected(0, 2) = 8.123 * 1.234567;
  expected(1, 2) = 0 * 1.234567;
  expected(2, 2) = 0.0004 * 1.234567;
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Overload, MulMat) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 3;
  source1(0, 1) = 27;
  source1(0, 2) = 18;
  source1(1, 0) = 0;
  source1(1, 1) = 18;
  source1(1, 2) = 15;
  source1(2, 0) = 24;
  source1(2, 1) = 9;
  source1(2, 2) = 9;

  source2(0, 0) = 3;
  source2(0, 1) = 18;
  source2(0, 2) = 24;
  source2(1, 0) = 21;
  source2(1, 1) = 15;
  source2(1, 2) = 24;
  source2(2, 0) = 0;
  source2(2, 1) = 27;
  source2(2, 2) = 3;

  expected(0, 0) = 576;
  expected(0, 1) = 945;
  expected(0, 2) = 774;
  expected(1, 0) = 378;
  expected(1, 1) = 675;
  expected(1, 2) = 477;
  expected(2, 0) = 261;
  expected(2, 1) = 810;
  expected(2, 2) = 819;

  S21Matrix result = source1 * source2;
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Overload, SumCut) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 352.412;
  source1(1, 0) = 1;
  source1(2, 0) = 1;
  source1(0, 1) = 1234.8234;
  source1(1, 1) = 0.00001;
  source1(2, 1) = 352.412;
  source1(0, 2) = 1234.8234;
  source1(1, 2) = 352.412;
  source1(2, 2) = 9;

  source2(0, 0) = 352.412;
  source2(1, 0) = 1;
  source2(2, 0) = 0;
  source2(0, 1) = -1234.8234;
  source2(1, 1) = 0.00001;
  source2(2, 1) = 123456789;
  source2(0, 2) = -0.00001;
  source2(1, 2) = 0.412;
  source2(2, 2) = 9;
  source1 += source2;
  expected(0, 0) = 352.412 + 352.412;
  expected(1, 0) = 1 + 1;
  expected(2, 0) = 1;
  expected(0, 1) = -1234.8234 + 1234.8234;
  expected(1, 1) = 0.00001 + 0.00001;
  expected(2, 1) = 352.412 + 123456789;
  expected(0, 2) = -0.00001 + 1234.8234;
  expected(1, 2) = 352.412 + 0.412;
  expected(2, 2) = 9 + 9;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(Overload, SubCut) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 352.412;
  source1(1, 0) = 1;
  source1(2, 0) = 1;
  source1(0, 1) = 1234.8234;
  source1(1, 1) = 0.00001;
  source1(2, 1) = 352.412;
  source1(0, 2) = 1234.8234;
  source1(1, 2) = 352.412;
  source1(2, 2) = 9;

  source2(0, 0) = 352.412;
  source2(1, 0) = 1;
  source2(2, 0) = 0;
  source2(0, 1) = -1234.8234;
  source2(1, 1) = 0.00001;
  source2(2, 1) = 123456789;
  source2(0, 2) = -0.00001;
  source2(1, 2) = 0.412;
  source2(2, 2) = 9;
  source1 -= source2;
  expected(0, 0) = 352.412 - 352.412;
  expected(1, 0) = 0;
  expected(2, 0) = 1;
  expected(0, 1) = 1234.8234 - -1234.8234;
  expected(1, 1) = 0.00001 - 0.00001;
  expected(2, 1) = 352.412 - 123456789;
  expected(0, 2) = 1234.8234 - -0.00001;
  expected(1, 2) = 352.412 - 0.412;
  expected(2, 2) = 0;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(Overload, MulNum1Cut) {
  S21Matrix source(3, 3);
  source(0, 0) = 1.3;
  source(1, 0) = 89.13;
  source(2, 0) = 1;
  source(0, 1) = 9.1;
  source(1, 1) = 7;
  source(2, 1) = 1389;
  source(0, 2) = 8.123;
  source(1, 2) = 0;
  source(2, 2) = 0.0004;
  source *= 1.234567;
  S21Matrix expected(3, 3);
  expected(0, 0) = 1.3 * 1.234567;
  expected(1, 0) = 89.13 * 1.234567;
  expected(2, 0) = 1 * 1.234567;
  expected(0, 1) = 9.1 * 1.234567;
  expected(1, 1) = 7 * 1.234567;
  expected(2, 1) = 1389 * 1.234567;
  expected(0, 2) = 8.123 * 1.234567;
  expected(1, 2) = 0 * 1.234567;
  expected(2, 2) = 0.0004 * 1.234567;
  ASSERT_EQ(source.EqMatrix(expected), 1);
}

TEST(Overload, MulMatCut) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 3;
  source1(0, 1) = 27;
  source1(0, 2) = 18;
  source1(1, 0) = 0;
  source1(1, 1) = 18;
  source1(1, 2) = 15;
  source1(2, 0) = 24;
  source1(2, 1) = 9;
  source1(2, 2) = 9;

  source2(0, 0) = 3;
  source2(0, 1) = 18;
  source2(0, 2) = 24;
  source2(1, 0) = 21;
  source2(1, 1) = 15;
  source2(1, 2) = 24;
  source2(2, 0) = 0;
  source2(2, 1) = 27;
  source2(2, 2) = 3;

  expected(0, 0) = 576;
  expected(0, 1) = 945;
  expected(0, 2) = 774;
  expected(1, 0) = 378;
  expected(1, 1) = 675;
  expected(1, 2) = 477;
  expected(2, 0) = 261;
  expected(2, 1) = 810;
  expected(2, 2) = 819;

  source1 *= source2;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(Overload, Equity) {
  S21Matrix a(5, 5), b(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      a(i, j) = b(i, j) = i + j;
    }
  }
  ASSERT_EQ(a == b, 1);
  ASSERT_EQ(b == a, 1);
}

TEST(Overload, Constant) {
  int size = 5;
  S21Matrix a(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      a(i, j) = i + j;
    }
  }
  S21Matrix b = a;
  ASSERT_DOUBLE_EQ(a(1, 1), b(1, 1));
}

TEST(SumMatrix, 1dMatrix) {
  S21Matrix source1, source2, expected;
  source1(0, 0) = 352.412;
  source2(0, 0) = 1234.8234;
  source1.SumMatrix(source2);
  expected(0, 0) = 352.412 + 1234.8234;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(SumMatrix, 3dMatrix) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 352.412;
  source1(1, 0) = 1;
  source1(2, 0) = 1;
  source1(0, 1) = 1234.8234;
  source1(1, 1) = 0.00001;
  source1(2, 1) = 352.412;
  source1(0, 2) = 1234.8234;
  source1(1, 2) = 352.412;
  source1(2, 2) = 9;

  source2(0, 0) = 352.412;
  source2(1, 0) = 1;
  source2(2, 0) = 0;
  source2(0, 1) = -1234.8234;
  source2(1, 1) = 0.00001;
  source2(2, 1) = 123456789;
  source2(0, 2) = -0.00001;
  source2(1, 2) = 0.412;
  source2(2, 2) = 9;
  source1.SumMatrix(source2);
  expected(0, 0) = 352.412 + 352.412;
  expected(1, 0) = 1 + 1;
  expected(2, 0) = 1;
  expected(0, 1) = -1234.8234 + 1234.8234;
  expected(1, 1) = 0.00001 + 0.00001;
  expected(2, 1) = 352.412 + 123456789;
  expected(0, 2) = -0.00001 + 1234.8234;
  expected(1, 2) = 352.412 + 0.412;
  expected(2, 2) = 9 + 9;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(SubMatrix, 1dMatrix) {
  S21Matrix source1, source2, expected;
  source1(0, 0) = 352.412;
  source2(0, 0) = 1234.8234;
  source1.SubMatrix(source2);
  expected(0, 0) = 352.412 - 1234.8234;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(SubMatrix, 3dMatrix) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 352.412;
  source1(1, 0) = 1;
  source1(2, 0) = 1;
  source1(0, 1) = 1234.8234;
  source1(1, 1) = 0.00001;
  source1(2, 1) = 352.412;
  source1(0, 2) = 1234.8234;
  source1(1, 2) = 352.412;
  source1(2, 2) = 9;

  source2(0, 0) = 352.412;
  source2(1, 0) = 1;
  source2(2, 0) = 0;
  source2(0, 1) = -1234.8234;
  source2(1, 1) = 0.00001;
  source2(2, 1) = 123456789;
  source2(0, 2) = -0.00001;
  source2(1, 2) = 0.412;
  source2(2, 2) = 9;
  source1.SubMatrix(source2);
  expected(0, 0) = 352.412 - 352.412;
  expected(1, 0) = 0;
  expected(2, 0) = 1;
  expected(0, 1) = 1234.8234 - -1234.8234;
  expected(1, 1) = 0.00001 - 0.00001;
  expected(2, 1) = 352.412 - 123456789;
  expected(0, 2) = 1234.8234 - -0.00001;
  expected(1, 2) = 352.412 - 0.412;
  expected(2, 2) = 0;
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(SumMatrix, Uninitialized) {
  S21Matrix source1, source2;
  ASSERT_EQ(source1.EqMatrix(source2), 1);
}

TEST(SubMatrix, Uninitialized) {
  S21Matrix source1, source2;
  ASSERT_EQ(source1.EqMatrix(source2), 1);
}


TEST(MulMatrix, 3dMatrices) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 1;
  source1(0, 1) = 1;
  source1(0, 2) = 2;
  source1(1, 0) = 2;
  source1(1, 1) = 4;
  source1(1, 2) = 5;
  source1(2, 0) = 12;
  source1(2, 1) = 13;
  source1(2, 2) = 14;

  source2(0, 0) = 1;
  source2(0, 1) = -4;
  source2(0, 2) = -4;
  source2(1, 0) = -7;
  source2(1, 1) = -7;
  source2(1, 2) = -16;
  source2(2, 0) = -16;
  source2(2, 1) = -17;
  source2(2, 2) = -17;

  expected(0, 0) = -38;
  expected(0, 1) = -45;
  expected(0, 2) = -54;
  expected(1, 0) = -106;
  expected(1, 1) = -121;
  expected(1, 2) = -157;
  expected(2, 0) = -303;
  expected(2, 1) = -377;
  expected(2, 2) = -494;

  source1.MulMatrix(source2);
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(MulMatrix, DifferentDimension) {
  S21Matrix source1(3, 3), source2(3, 1), expected(3, 1);
  source1(0, 0) = 5;
  source1(0, 1) = 8;
  source1(0, 2) = -4;
  source1(1, 0) = 6;
  source1(1, 1) = 9;
  source1(1, 2) = -5;
  source1(2, 0) = 4;
  source1(2, 1) = 7;
  source1(2, 2) = -2;

  source2(0, 0) = 2;
  source2(1, 0) = -3;
  source2(2, 0) = 1;

  expected(0, 0) = -18;
  expected(1, 0) = -20;
  expected(2, 0) = -15;

  source1.MulMatrix(source2);
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(MulMatrix, BigMatrices) {
  S21Matrix source1(2, 4), source2(4, 6), expected(2, 6);
  source1(0, 0) = 9;
  source1(0, 1) = 9;
  source1(0, 2) = 2;
  source1(0, 3) = 8;
  source1(1, 0) = 6;
  source1(1, 1) = 7;
  source1(1, 2) = 8;
  source1(1, 3) = 5;

  source2(0, 0) = 2;
  source2(0, 1) = 5;
  source2(0, 2) = 6;
  source2(0, 3) = 8;
  source2(0, 4) = 5;
  source2(0, 5) = 1;
  source2(1, 0) = 0;
  source2(1, 1) = 7;
  source2(1, 2) = 6;
  source2(1, 3) = 4;
  source2(1, 4) = 8;
  source2(1, 5) = 9;
  source2(2, 0) = 0;
  source2(2, 1) = 7;
  source2(2, 2) = 1;
  source2(2, 3) = 6;
  source2(2, 4) = 2;
  source2(2, 5) = 7;
  source2(3, 0) = 1;
  source2(3, 1) = 4;
  source2(3, 2) = 8;
  source2(3, 3) = 4;
  source2(3, 4) = 0;
  source2(3, 5) = 6;

  expected(0, 0) = 26;
  expected(0, 1) = 154;
  expected(0, 2) = 174;
  expected(0, 3) = 152;
  expected(0, 4) = 121;
  expected(0, 5) = 152;
  expected(1, 0) = 17;
  expected(1, 1) = 155;
  expected(1, 2) = 126;
  expected(1, 3) = 144;
  expected(1, 4) = 102;
  expected(1, 5) = 155;

  source1.MulMatrix(source2);
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(MulMatrix, 3dMatrices2) {
  S21Matrix source1(3, 3), source2(3, 3), expected(3, 3);
  source1(0, 0) = 3;
  source1(0, 1) = 27;
  source1(0, 2) = 18;
  source1(1, 0) = 0;
  source1(1, 1) = 18;
  source1(1, 2) = 15;
  source1(2, 0) = 24;
  source1(2, 1) = 9;
  source1(2, 2) = 9;

  source2(0, 0) = 3;
  source2(0, 1) = 18;
  source2(0, 2) = 24;
  source2(1, 0) = 21;
  source2(1, 1) = 15;
  source2(1, 2) = 24;
  source2(2, 0) = 0;
  source2(2, 1) = 27;
  source2(2, 2) = 3;

  expected(0, 0) = 576;
  expected(0, 1) = 945;
  expected(0, 2) = 774;
  expected(1, 0) = 378;
  expected(1, 1) = 675;
  expected(1, 2) = 477;
  expected(2, 0) = 261;
  expected(2, 1) = 810;
  expected(2, 2) = 819;

  source1.MulMatrix(source2);
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(MulMatrix, EmptyMatrices) {
  S21Matrix source1(19, 9), source2(9, 14), expected(19, 14);
  source1.MulMatrix(source2);
  ASSERT_EQ(source1.EqMatrix(expected), 1);
}

TEST(Transpose, 1dMatrix) {
  S21Matrix source, expected;
  source(0, 0) = 123;
  expected(0, 0) = 123;
  S21Matrix result = source.Transpose();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Transpose, 3dMatrix) {
  S21Matrix source(3, 3), expected(3, 3);
  source(0, 0) = 352.412;
  source(1, 0) = 1;
  source(2, 0) = 1;
  source(0, 1) = 1234.8234;
  source(1, 1) = 0.00001;
  source(2, 1) = 352.412;
  source(0, 2) = 1234.8234;
  source(1, 2) = 352.412;
  source(2, 2) = 9;
  expected(0, 0) = 352.412;
  expected(0, 1) = 1;
  expected(0, 2) = 1;
  expected(1, 0) = 1234.8234;
  expected(1, 1) = 0.00001;
  expected(1, 2) = 352.412;
  expected(2, 0) = 1234.8234;
  expected(2, 1) = 352.412;
  expected(2, 2) = 9;
  S21Matrix result = source.Transpose();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(Transpose, 3x4Matrix) {
  S21Matrix source(3, 4), expected(4, 3);
  source(0, 0) = 352.412;
  source(1, 0) = 1;
  source(2, 0) = 1;
  source(0, 1) = 1234.8234;
  source(1, 1) = 0.00001;
  source(2, 1) = 352.412;
  source(0, 2) = 1234.8234;
  source(1, 2) = 352.412;
  source(2, 2) = 9;
  source(0, 3) = 13;
  source(1, 3) = 32.42;
  source(2, 3) = 0.9;
  expected(0, 0) = 352.412;
  expected(0, 1) = 1;
  expected(0, 2) = 1;
  expected(1, 0) = 1234.8234;
  expected(1, 1) = 0.00001;
  expected(1, 2) = 352.412;
  expected(2, 0) = 1234.8234;
  expected(2, 1) = 352.412;
  expected(2, 2) = 9;
  expected(3, 0) = 13;
  expected(3, 1) = 32.42;
  expected(3, 2) = 0.9;
  ASSERT_EQ(source.Transpose().EqMatrix(expected), 1);
}

TEST(Transpose, 4x3Matrix) {
  S21Matrix source(4, 3), expected(3, 4);
  source(0, 0) = 352.412;
  source(1, 0) = 1;
  source(2, 0) = 1;
  source(3, 0) = 1234.8234;
  source(0, 1) = 0.00001;
  source(1, 1) = 352.412;
  source(2, 1) = 1234.8234;
  source(3, 1) = 352.412;
  source(0, 2) = 9;
  source(1, 2) = 13;
  source(2, 2) = 32.42;
  source(3, 2) = 0.9;
  expected(0, 0) = 352.412;
  expected(0, 1) = 1;
  expected(0, 2) = 1;
  expected(0, 3) = 1234.8234;
  expected(1, 0) = 0.00001;
  expected(1, 1) = 352.412;
  expected(1, 2) = 1234.8234;
  expected(1, 3) = 352.412;
  expected(2, 0) = 9;
  expected(2, 1) = 13;
  expected(2, 2) = 32.42;
  expected(2, 3) = 0.9;
  ASSERT_EQ(source.Transpose().EqMatrix(expected), 1);
}

TEST(Complements, SizeError) {
  S21Matrix source(2, 1);
  EXPECT_THROW(source.CalcComplements(), std::bad_array_new_length);
}

TEST(Complements, EmptyMatrix) {
  S21Matrix source;
  EXPECT_THROW(source.CalcComplements(), std::bad_array_new_length);
}

TEST(Determinant, WrongSize) {
  S21Matrix source(3, 9);
  EXPECT_THROW(source.Determinant(), std::invalid_argument);
}

TEST(InverseMatrix, Uninitialized) {
  S21Matrix source;
  EXPECT_THROW(source.InverseMatrix(), std::logic_error);
}

TEST(InverseMatrix, AllZero) {
  S21Matrix source(10, 10);
  EXPECT_THROW(source.InverseMatrix(), std::logic_error);
}

TEST(InverseMatrix, WrongSize) {
  S21Matrix source(10, 9);
  EXPECT_THROW(source.InverseMatrix(), std::invalid_argument);
}

TEST(MulMatrix, Size_error) {
  S21Matrix source1(2, 2), source2(5, 5);
  EXPECT_THROW(source1.MulMatrix(source2), std::invalid_argument);
}

TEST(Index, OutOfRange) {
  S21Matrix source1(3, 3);
  EXPECT_THROW(source1(12, 4), std::invalid_argument);
}

TEST(Seter, LessThanRows) {
  S21Matrix source;
  EXPECT_THROW(source.SetRows(-3), std::invalid_argument);
}

TEST(Seter, LessThanCols) {
  S21Matrix source;
  EXPECT_THROW(source.SetColumns(-3), std::invalid_argument);
}

TEST(Constructors, WrongIndex) {
  EXPECT_THROW(S21Matrix source(-1, -1), std::bad_array_new_length);
}

TEST(Overload, WrongIndex) {
  const S21Matrix a(9, 9);
  S21Matrix b;
  b = a;
  EXPECT_EQ(b.EqMatrix(a), 1);
}

TEST(SumMatrix, DiffSize) {
  S21Matrix source1(3, 2), source2(2, 3);
  EXPECT_THROW(source1.SumMatrix(source2), std::invalid_argument);
  EXPECT_THROW(source2.SumMatrix(source1), std::invalid_argument);
}

TEST(SubMatrix, DiffSize) {
  S21Matrix source1(3, 2), source2(2, 3);
  EXPECT_THROW(source1.SubMatrix(source2), std::invalid_argument);
  EXPECT_THROW(source2.SubMatrix(source1), std::invalid_argument);
}

TEST(Inverse, Uncorrect) {
  S21Matrix source1(3, 2);
  EXPECT_THROW(source1.InverseMatrix(), std::invalid_argument);
}

TEST(Constructors, Move) {
  S21Matrix source(3, 3);
  source(0, 0) = 99;
  source(2, 2) = -99;
  source(1, 1) = 13;
  S21Matrix moved_matrix(std::move(source));
  ASSERT_EQ(source.EqMatrix(moved_matrix), 0);
  ASSERT_EQ(moved_matrix(0, 0), 99);
  ASSERT_EQ(moved_matrix(1, 1), 13);
  ASSERT_EQ(moved_matrix(2, 2), -99);
}

TEST(InverseMatrix, BigMatrix) {
  int size = 8;
  S21Matrix source(size, size), expected(size, size);
  source(0, 0) = 2;
  source(0, 1) = 8;
  source(0, 2) = 7;
  source(0, 3) = 4;
  source(0, 4) = 1;
  source(0, 5) = 8;
  source(0, 6) = 3;
  source(0, 7) = 9;
  source(1, 0) = 4;
  source(1, 1) = 2;
  source(1, 2) = 6;
  source(1, 3) = 2;
  source(1, 4) = 2;
  source(1, 5) = 1;
  source(1, 6) = 5;
  source(1, 7) = 8;
  source(2, 0) = 8;
  source(2, 1) = 6;
  source(2, 2) = 7;
  source(2, 3) = 7;
  source(2, 4) = 3;
  source(2, 5) = 4;
  source(2, 6) = 4;
  source(2, 7) = 1;
  source(3, 0) = 1;
  source(3, 1) = 7;
  source(3, 2) = 0;
  source(3, 3) = 4;
  source(3, 4) = 4;
  source(3, 5) = 3;
  source(3, 6) = 0;
  source(3, 7) = 5;
  source(4, 0) = 5;
  source(4, 1) = 7;
  source(4, 2) = 5;
  source(4, 3) = 6;
  source(4, 4) = 8;
  source(4, 5) = 3;
  source(4, 6) = 1;
  source(4, 7) = 9;
  source(5, 0) = 3;
  source(5, 1) = 7;
  source(5, 2) = 8;
  source(5, 3) = 0;
  source(5, 4) = 5;
  source(5, 5) = 7;
  source(5, 6) = 0;
  source(5, 7) = 2;
  source(6, 0) = 5;
  source(6, 1) = 8;
  source(6, 2) = 3;
  source(6, 3) = 5;
  source(6, 4) = 9;
  source(6, 5) = 1;
  source(6, 6) = 2;
  source(6, 7) = 0;
  source(7, 0) = 7;
  source(7, 1) = 8;
  source(7, 2) = 7;
  source(7, 3) = 4;
  source(7, 4) = 7;
  source(7, 5) = 9;
  source(7, 6) = 1;
  source(7, 7) = 5;

  expected(0, 0) = -0.5349902183;
  expected(0, 1) = 0.2894503762;
  expected(0, 2) = 0.2648128502;
  expected(0, 3) = 0.6295578936;
  expected(0, 4) = -0.1684575429;
  expected(0, 5) = 0.2471263249;
  expected(0, 6) = -0.3773947292;
  expected(0, 7) = 0.0217143747;
  expected(1, 0) = -0.3358379646;
  expected(1, 1) = 0.2037511071;
  expected(1, 2) = 0.2032547229;
  expected(1, 3) = 0.6234293334;
  expected(1, 4) = -0.1799149334;
  expected(1, 5) = 0.3295114996;
  expected(1, 6) = -0.2254070837;
  expected(1, 7) = -0.1935314328;
  expected(2, 0) = 0.09452225456;
  expected(2, 1) = -0.09221066155;
  expected(2, 2) = 0.03813722914;
  expected(2, 3) = -0.2190871073;
  expected(2, 4) = 0.1695573745;
  expected(2, 5) = 0.1092580516;
  expected(2, 6) = 0.007715043036;
  expected(2, 7) = -0.1600498331;
  expected(3, 0) = 0.3630563639;
  expected(3, 1) = -0.3052665388;
  expected(3, 2) = -0.04656927155;
  expected(3, 3) = -0.4771776828;
  expected(3, 4) = 0.2389343637;
  expected(3, 5) = -0.2685487089;
  expected(3, 6) = 0.1928760759;
  expected(3, 7) = -0.001245826966;
  expected(4, 0) = 0.2619837848;
  expected(4, 1) = -0.133556544;
  expected(4, 2) = -0.2495968906;
  expected(4, 3) = -0.4562289726;
  expected(4, 4) = 0.1044612934;
  expected(4, 5) = -0.2245895097;
  expected(4, 6) = 0.3128420752;
  expected(4, 7) = 0.1500734843;
  expected(5, 0) = 0.2992174649;
  expected(5, 1) = -0.1560300945;
  expected(5, 2) = -0.1850280149;
  expected(5, 3) = -0.3646314915;
  expected(5, 4) = -0.02339656554;
  expected(5, 5) = -0.2701059926;
  expected(5, 6) = 0.1915783395;
  expected(5, 7) = 0.2628500238;
  expected(6, 0) = 0.3028673486;
  expected(6, 1) = 0.0418714657;
  expected(6, 2) = -0.2001336669;
  expected(6, 3) = -0.3106910771;
  expected(6, 4) = -0.1692459178;
  expected(6, 5) = -0.2826713255;
  expected(6, 6) = 0.3477738954;
  expected(6, 7) = 0.1562734201;
  expected(7, 0) = -0.1023914038;
  expected(7, 1) = 0.1015348978;
  expected(7, 2) = 0.0104305565;
  expected(7, 3) = 0.1667915738;
  expected(7, 4) = 0.02489382894;
  expected(7, 5) = 0.04583280613;
  expected(7, 6) = -0.1284726616;
  expected(7, 7) = -0.01017100922;

  S21Matrix result = source.InverseMatrix();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(InverseMatrix, 3dMatrix) {
  int size = 3;
  S21Matrix source(size, size), expected(size, size);
  source(0, 0) = 3;
  source(0, 1) = 27;
  source(0, 2) = 18;
  source(1, 0) = 0;
  source(1, 1) = 18;
  source(1, 2) = 15;
  source(2, 0) = 24;
  source(2, 1) = 9;
  source(2, 2) = 9;

  expected(0, 0) = 0.01333333333;
  expected(0, 1) = -0.04;
  expected(0, 2) = 0.04;
  expected(1, 0) = 0.1777777778;
  expected(1, 1) = -0.2;
  expected(1, 2) = -0.02222222222;
  expected(2, 0) = -0.2133333333;
  expected(2, 1) = 0.3066666667;
  expected(2, 2) = 0.02666666667;

  S21Matrix result = source.InverseMatrix();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(InverseMatrix, 3dMatrix2) {
  int size = 3;
  S21Matrix source(size, size), expected(size, size);
  source(0, 0) = 4;
  source(0, 1) = 6;
  source(0, 2) = 8;
  source(1, 0) = 9;
  source(1, 1) = 2;
  source(1, 2) = 7;
  source(2, 0) = 9;
  source(2, 1) = 1;
  source(2, 2) = 0;

  expected(0, 0) = -0.02517985612;
  expected(0, 1) = 0.02877697842;
  expected(0, 2) = 0.09352517986;
  expected(1, 0) = 0.226618705;
  expected(1, 1) = -0.2589928058;
  expected(1, 2) = 0.1582733813;
  expected(2, 0) = -0.03237410072;
  expected(2, 1) = 0.1798561151;
  expected(2, 2) = -0.1654676259;

  S21Matrix result = source.InverseMatrix();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

TEST(InverseMatrix, 8dMatrix) {
  int size = 8;
  S21Matrix source(size, size), expected(size, size);
  source(0, 0) = 2;
  source(0, 1) = 8;
  source(0, 2) = 7;
  source(0, 3) = 4;
  source(0, 4) = 1;
  source(0, 5) = 8;
  source(0, 6) = 3;
  source(0, 7) = 9;
  source(1, 0) = 4;
  source(1, 1) = 2;
  source(1, 2) = 6;
  source(1, 3) = 2;
  source(1, 4) = 2;
  source(1, 5) = 1;
  source(1, 6) = 5;
  source(1, 7) = 8;
  source(2, 0) = 8;
  source(2, 1) = 6;
  source(2, 2) = 7;
  source(2, 3) = 7;
  source(2, 4) = 3;
  source(2, 5) = 4;
  source(2, 6) = 4;
  source(2, 7) = 1;
  source(3, 0) = 1;
  source(3, 1) = 7;
  source(3, 2) = 0;
  source(3, 3) = 4;
  source(3, 4) = 4;
  source(3, 5) = 3;
  source(3, 6) = 0;
  source(3, 7) = 5;
  source(4, 0) = 5;
  source(4, 1) = 7;
  source(4, 2) = 5;
  source(4, 3) = 6;
  source(4, 4) = 8;
  source(4, 5) = 3;
  source(4, 6) = 1;
  source(4, 7) = 9;
  source(5, 0) = 3;
  source(5, 1) = 7;
  source(5, 2) = 8;
  source(5, 3) = 0;
  source(5, 4) = 5;
  source(5, 5) = 7;
  source(5, 6) = 0;
  source(5, 7) = 2;
  source(6, 0) = 5;
  source(6, 1) = 8;
  source(6, 2) = 3;
  source(6, 3) = 5;
  source(6, 4) = 9;
  source(6, 5) = 1;
  source(6, 6) = 2;
  source(6, 7) = 0;
  source(7, 0) = 7;
  source(7, 1) = 8;
  source(7, 2) = 7;
  source(7, 3) = 4;
  source(7, 4) = 7;
  source(7, 5) = 9;
  source(7, 6) = 1;
  source(7, 7) = 5;

  expected(0, 0) = -0.5349902183;
  expected(0, 1) = 0.2894503762;
  expected(0, 2) = 0.2648128502;
  expected(0, 3) = 0.6295578936;
  expected(0, 4) = -0.1684575429;
  expected(0, 5) = 0.2471263249;
  expected(0, 6) = -0.3773947292;
  expected(0, 7) = 0.0217143747;
  expected(1, 0) = -0.3358379646;
  expected(1, 1) = 0.2037511071;
  expected(1, 2) = 0.2032547229;
  expected(1, 3) = 0.6234293334;
  expected(1, 4) = -0.1799149334;
  expected(1, 5) = 0.3295114996;
  expected(1, 6) = -0.2254070837;
  expected(1, 7) = -0.1935314328;
  expected(2, 0) = 0.09452225456;
  expected(2, 1) = -0.09221066155;
  expected(2, 2) = 0.03813722914;
  expected(2, 3) = -0.2190871073;
  expected(2, 4) = 0.1695573745;
  expected(2, 5) = 0.1092580516;
  expected(2, 6) = 0.007715043036;
  expected(2, 7) = -0.1600498331;
  expected(3, 0) = 0.3630563639;
  expected(3, 1) = -0.3052665388;
  expected(3, 2) = -0.04656927155;
  expected(3, 3) = -0.4771776828;
  expected(3, 4) = 0.2389343637;
  expected(3, 5) = -0.2685487089;
  expected(3, 6) = 0.1928760759;
  expected(3, 7) = -0.001245826966;
  expected(4, 0) = 0.2619837848;
  expected(4, 1) = -0.133556544;
  expected(4, 2) = -0.2495968906;
  expected(4, 3) = -0.4562289726;
  expected(4, 4) = 0.1044612934;
  expected(4, 5) = -0.2245895097;
  expected(4, 6) = 0.3128420752;
  expected(4, 7) = 0.1500734843;
  expected(5, 0) = 0.2992174649;
  expected(5, 1) = -0.1560300945;
  expected(5, 2) = -0.1850280149;
  expected(5, 3) = -0.3646314915;
  expected(5, 4) = -0.02339656554;
  expected(5, 5) = -0.2701059926;
  expected(5, 6) = 0.1915783395;
  expected(5, 7) = 0.2628500238;
  expected(6, 0) = 0.3028673486;
  expected(6, 1) = 0.0418714657;
  expected(6, 2) = -0.2001336669;
  expected(6, 3) = -0.3106910771;
  expected(6, 4) = -0.1692459178;
  expected(6, 5) = -0.2826713255;
  expected(6, 6) = 0.3477738954;
  expected(6, 7) = 0.1562734201;
  expected(7, 0) = -0.1023914038;
  expected(7, 1) = 0.1015348978;
  expected(7, 2) = 0.0104305565;
  expected(7, 3) = 0.1667915738;
  expected(7, 4) = 0.02489382894;
  expected(7, 5) = 0.04583280613;
  expected(7, 6) = -0.1284726616;
  expected(7, 7) = -0.01017100922;

  S21Matrix result = source.InverseMatrix();
  ASSERT_EQ(result.EqMatrix(expected), 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}