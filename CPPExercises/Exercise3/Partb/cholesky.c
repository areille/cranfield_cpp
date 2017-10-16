
/* 
* Factorises the symmetric, positive definite matrix a into CC^{T} 
* where C is lower triangular. Output is the matrix C.
*/
void cholesky_fact(double** a, int n, double** c)
{
    int i,j,k;
	double temp;
	
	for (j=0;j<n;j++)
	{
		temp=0.0;
		
		for (k=0;k<j;k++) {
			temp=temp+pow((c[j][k]),2);
		}
		
		if ((a[j][j]-temp) <= 0.0) {
			printf("zero or negative pivot found, matrix is not psoitive definite");
			exit(1);
		}

		c[j][j]=sqrt(a[j][j]-temp);	
		
		for (i=j+1;i<n;i++)
		{
			temp=0.0;
			for (k=0;k<j;k++)
			{
				temp=temp+(c[i][k])*(c[j][k]);
			}
			c[i][j]=((a[i][j])-temp)/(c[j][j]);
		}
	}
}


/* 
* Solves the system CC^{T}x = b where C is a lower triangular
* matrix resultng from factorisation of a symmetric positive definite
* marix. Uses forward and backward substition 
*/
void cholesky_solve(double** c, double* b, int n, double* x)
{
	int i,j;
	double* temp;

	temp = vector(n);
	copy_vector(b,temp,n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) 
			temp[i] -= c[i][j]*temp[j];
		temp[i] = temp[i]/c[i][i];
	}

	for (i = n - 1; i >= 0; i--) {
		for (j = i + 1; j < n; j++) temp[i] -= c[j][i]*temp[j];
		temp[i] /= c[i][i];
	}

	for (i=0; i<n; i++) x[i] = temp[i];

	free_vector(temp,n);
}
