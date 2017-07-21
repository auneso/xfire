#include "bignum.h"


#define GCD_PAIR_COUNT  3

static const int gcd_pairs[GCD_PAIR_COUNT][3] =
{
  { 693, 609, 21 },
  { 1764, 868, 28 },
  { 768454923, 542167814, 1 }
};

/*
 * Checkup routine
 */
int mpi_self_test (int verbose)
{
  int ret, i;
  mpi A, E, N, X, Y, U, V;

  mpi_init(&A); mpi_init(&E); mpi_init(&N); mpi_init(&X);
  mpi_init(&Y); mpi_init(&U); mpi_init(&V);

  MPI_CHK(mpi_read_string(&A, 16,
    "EFE021C2645FD1DC586E69184AF4A31E" \
    "D5F53E93B5F123FA41680867BA110131" \
    "944FE7952E2517337780CB0DB80E61AA" \
    "E7C8DDC6C5C6AADEB34EB38A2F40D5E6"));

  MPI_CHK(mpi_read_string(&E, 16,
    "B2E7EFD37075B9F03FF989C7C5051C20" \
    "34D2A323810251127E7BF8625A4F49A5" \
    "F3E27F4DA8BD59C47D6DAABA4C8127BD" \
    "5B5C25763222FEFCCFC38B832366C29E"));

  MPI_CHK(mpi_read_string(&N, 16,
    "0066A198186C18C10B2F5ED9B522752A" \
    "9830B69916E535C8F047518A889A43A5" \
    "94B6BED27A168D31D4A52F88925AA8F5"));

  MPI_CHK(mpi_mul_mpi(&X, &A, &N));

  MPI_CHK(mpi_read_string(&U, 16,
    "602AB7ECA597A3D6B56FF9829A5E8B85" \
    "9E857EA95A03512E2BAE7391688D264A" \
    "A5663B0341DB9CCFD2C4C5F421FEC814" \
    "8001B72E848A38CAE1C65F78E56ABDEF" \
    "E12D3C039B8A02D6BE593F0BBBDA56F1" \
    "ECF677152EF804370C1A305CAF3B5BF1" \
    "30879B56C61DE584A0F53A2447A51E"));

  if (verbose != 0)
    printf("  MPI test #1 (mul_mpi): ");

  if (mpi_cmp_mpi(&X, &U) != 0)
  {
    if (verbose != 0)
      printf("failed\n");

    return(1);
  }

  if (verbose != 0)
    printf("passed\n");

  MPI_CHK(mpi_div_mpi(&X, &Y, &A, &N));

  MPI_CHK(mpi_read_string(&U, 16,
    "256567336059E52CAE22925474705F39A94"));

  MPI_CHK(mpi_read_string(&V, 16,
    "6613F26162223DF488E9CD48CC132C7A" \
    "0AC93C701B001B092E4E5B9F73BCD27B" \
    "9EE50D0657C77F374E903CDFA4C642"));

  if (verbose != 0)
    printf("  MPI test #2 (div_mpi): ");

  if (mpi_cmp_mpi(&X, &U) != 0 || mpi_cmp_mpi(&Y, &V) != 0)
  {
    if (verbose != 0)
      printf("failed\n");

    return(1);
  }

  if (verbose != 0)
    printf("passed\n");

  MPI_CHK(mpi_exp_mod(&X, &A, &E, &N, NULL));

  MPI_CHK(mpi_read_string(&U, 16,
    "36E139AEA55215609D2816998ED020BB" \
    "BD96C37890F65171D948E9BC7CBAA4D9" \
    "325D24D6A3C12710F10A09FA08AB87"));

  if (verbose != 0)
    printf("  MPI test #3 (exp_mod): ");

  if (mpi_cmp_mpi(&X, &U) != 0)
  {
    if (verbose != 0)
      printf("failed\n");

    return(1);
  }

  if (verbose != 0)
    printf("passed\n");

#if defined(POLARSSL_GENPRIME)
  MPI_CHK(mpi_inv_mod(&X, &A, &N));

  MPI_CHK(mpi_read_string(&U, 16,
    "003A0AAEDD7E784FC07D8F9EC6E3BFD5" \
    "C3DBA76456363A10869622EAC2DD84EC" \
    "C5B8A74DAC4D09E03B5E0BE779F2DF61"));

  if (verbose != 0)
    printf("  MPI test #4 (inv_mod): ");

  if (mpi_cmp_mpi(&X, &U) != 0)
  {
    if (verbose != 0)
      printf("failed\n");

    return(1);
  }

  if (verbose != 0)
    printf("passed\n");
#endif

  if (verbose != 0)
    printf("  MPI test #5 (simple gcd): ");

  for (i = 0; i < GCD_PAIR_COUNT; i++)
  {
    MPI_CHK(mpi_lset(&X, gcd_pairs[i][0]));
    MPI_CHK(mpi_lset(&Y, gcd_pairs[i][1]));

      MPI_CHK(mpi_gcd(&A, &X, &Y));

      if (mpi_cmp_int(&A, gcd_pairs[i][2]) != 0)
      {
          if (verbose != 0)
              printf("failed at %d\n", i);

          return(1);
      }
  }

  if (verbose != 0)
    printf("passed\n");

cleanup:

  if (ret != 0 && verbose != 0)
    printf("Unexpected error, return code = %08X\n", ret);

  mpi_free(&A); mpi_free(&E); mpi_free(&N); mpi_free(&X);
  mpi_free(&Y); mpi_free(&U); mpi_free(&V);

  if (verbose != 0)
    printf("\n");

  return(ret);
}

int main (int argc, char *argv[])
{
  mpi_self_test(1);
  return 0;
}

