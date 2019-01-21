#include<iostream>
#include<sstream>
#include<time.h>
using namespace std;

float hitung(float a,float b,string c)
{
	if(c == "+")
	{
		return (a+b);
	} else if (c == "-")
	{
		return(a-b);
	} else if (c == "*")
	{
		return (a*b);
	} else if (c == "/");
	{
		return (a/b);
	}
}

string generate(int x)
{
	if(x == 1)
	{
		return("+");
	} else if (x == 2)
	{
		return("-");
	} else if (x == 3)
	{
		return("*");
	} else 
	{
		return("/");
	}
}

bool isExist(string save[10000],string stemp,int c)
{
	bool found = false;

	int i = 1;
	while(not found and i<=c)
	{
		if(save[i] == stemp)
		{
			found = true;
		} else
		{
			i++;
		}
	}
	return found;
}
int main()
{
	int a[5];
	string stemp,opr1,opr2,opr3;
	string save[10000];
	int c = 0;
	stringstream s1,s2,s3,s4;
	clock_t start, end;
    start = clock();
	for(int i=1;i<=4;i++)
	{
		cin>>a[i];
	}
	int i=1;
	while(i<=4)
	{
		int j = 1;
		while(j<=4)
		{
			if (j != i)
			{
				int k = 1;
				while(k<=4)
				{
					if(k != j and k != i)
					{
						int l = 1;
						while(l<=4)
						{
							if(l != k and l != j and l != i)
							{
								for(int m = 1;m<=4;m++)
								{
									for(int n = 1;n<=4;n++)
									{
										for(int o = 1;o<=4;o++)
										{
											stringstream s1,s2,s3,s4;
											opr1 = generate(m);
											opr2 = generate(n);
											opr3 = generate(o);
											s1 << a[i];
											s2 << a[j];
											s3 << a[k];
											s4 << a[l];
											// ((A opr1 B) opr2 C) opr3 D
											if(hitung(hitung(hitung((float)a[i],(float)a[j],opr1),(float)a[k],opr2),(float)a[l],opr3) == 24)
											{
												stemp = "(("+s1.str()+" "+opr1+" "+s2.str()+")"+" "+opr2+" "+s3.str()+")"+" "+opr3+" "+s4.str();
												if(!isExist(save,stemp,c))
												{
													c++;
													save[c] = stemp;
												}	
											}	
											// (A opr1 (B opr2 C)) opr3 D
											if(hitung(hitung(a[i],hitung((float)a[j],(float)a[k],opr2),opr1),(float)a[l],opr3) == 24)
											{
												stemp = "("+s1.str()+" "+opr1+" ("+s2.str()+" "+opr2+" "+s3.str()+")) "+opr3+" "+s4.str();
												if(!isExist(save,stemp,c))
												{
													c++;
													save[c] = stemp;
												}	
											}
											// (A opr1 B) opr2 (C opr3 D) 
											if(hitung(hitung((float)a[i],(float)a[j],opr1),hitung((float)a[k],(float)a[l],opr3),opr2) == 24)
											{
												stemp = "("+s1.str()+" "+opr1+" "+s2.str()+") "+opr2+" ("+s3.str()+" "+opr3+" "+s4.str()+")";
												if(!isExist(save,stemp,c))
												{
													c++;
													save[c] = stemp;
												}
											}
											// A opr1 ((B opr2 C) opr3 D) 
											if(hitung((float)a[i],hitung(hitung((float)a[j],(float)a[k],opr2),(float)a[l],opr3),opr1) == 24)
											{
												stemp = s1.str()+" "+opr1+" (("+s2.str()+" "+opr2+" "+s3.str()+") "+opr3+" "+s4.str()+")";
												if(!isExist(save,stemp,c))
												{
													c++;
													save[c] = stemp;
												}
											}
										}
									}									
								}
							}
							l++;
						}
					}
					k++;	
				}
			}
			j++;
		}
		i++;
	}
	for(int i = 1;i<=c;i++)
	{
		cout<<save[i]<<endl;
	}
	if(c == 0)
	{
		cout<<"Tidak ada kombinasi angka untuk membentuk 24"<<endl;
	} else
	{
		cout<<"Ada sebanyak "<<c<<" kombinasi untuk membentuk angka 24"<<endl;
	}
	end = clock();
    double duration_sec = double(end-start)/CLOCKS_PER_SEC;
    cout<<"Execution time : "<<duration_sec<<" s"<<endl;
}