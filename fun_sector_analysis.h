/*****SECTOR ANALYSIS*****/


EQUATION("Inverse_Herf_Index")
/*
Sector Variable for Analysis
*/
	v[0]=0;                           //initializes the CYCLE    
	CYCLE(cur, "FIRMS")               //CYCLE trought all firms of the sector
	{
		v[1]=VS(cur, "Market_Share");   //firm's market share
		v[0]=v[0]+v[1]*v[1];            //sums up firm's market share squared
	}
	if(v[0]!=0)                       //if the sum of the market share squared is not zero
  	v[2]=1/v[0];                    //the index is the inverse of the sum of the market share squared
	else                              //if the sum of the market share squared is zero
  	v[2]=0;                         //the index is zero
RESULT(v[2])


EQUATION("Herf_Index")
/*
Sector Variable for Analysis
*/
	v[0]=0;                           //initializes the CYCLE    
	CYCLE(cur, "FIRMS")               //CYCLE trought all firms of the sector
	{
		v[1]=VS(cur, "Market_Share");   //firm's market share
		v[0]=v[0]+v[1]*v[1];            //sums up firm's market share squared
	}
RESULT(v[0])


EQUATION("Degree_Asymmetry")
/*
Sector Variable for Analysis
*/
	STAT("Degree_Competition");         //calculates variance, and other statistics, of the degree of competition    
	if(v[2]>0)                          //if the variance is positive
		v[7]=pow(v[2],0.5);               //degree of assimetry of the sector
	else                                //if the variance is not positive
		v[7]=0;                           //degree of assimetry is zero
RESULT(v[7])


EQUATION("Number_Firms")
/*
Sector Variable for Analysis
*/
	STAT("Degree_Competition");         //calculates statistics of the degree of competition, v[0] is the number of instances 
RESULT(v[0])


EQUATION("Turbulence")
/*
Sector Variable for Analysis
*/
	v[0]=0;                                           //initializes the CYCLE 
	CYCLE(cur, "FIRMS")                               //CYCLE trough all firms 
	{
	v[1]=VS(cur,"firm_date_birth");                   //firm's date of birth
 	if(v[1]==(double)t)                               //if the time period is the same of the firm's date of birth
 		v[4]=0;                                         //use zero
 	else                                              //if the time period is no the same of the firm's date of birth
 		{
 		v[2]=VS(cur,"Effective_Market_Share");          //firm's effective market share in current period
 		v[3]=VLS(cur,"Effective_Market_Share",1);       //firm's effective market share in the last period
 		v[4]=abs(v[2]-v[3]);                            //returns the absolute value of the difference
 		}
 	v[0]=v[0]+v[4];                                   //sums up all absolute values for all firms
	}
	v[5]=V("Effective_Market_Share_Exit");            //
	v[6]=v[0]+v[5];                                   //
RESULT(v[6])
