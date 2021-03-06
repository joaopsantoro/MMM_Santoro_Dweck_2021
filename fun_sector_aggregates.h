/*****SECTOR AGGREGATES*****/



EQUATION("Sales_Sector")                          
/*
Sum up the sales of all firms in the sector
*/
	v[0]=SUM("Sales");                                     
RESULT(v[0])


EQUATION("Demand_Met")
/*
Percentage of demand fulfilled by each sector
*/
	v[0]=V("Effective_Orders_Sector");                     //total effective orders of the sector
	v[1]=V("Sales_Sector");                                //total sales of the sector
  	if(v[0]>0)                                           //if effective orders is positive
    	v[2]=v[1]/v[0];                                    //the percentage of the demand met by the sector will be the total sales over effective orders
  	else                                                 //if effective orders is not positive
    	v[2]=1;                                            //the percentage of the demand met by the sector is 100%
RESULT(v[2])


EQUATION("Inventories_Sector")
/*
Sum of the Inventories 
*/
	v[0]=SUM("Inventories");                                
RESULT(v[0])


EQUATION("Effective_Production_Sector")
/*
Sum of the Effective Production 
*/
	v[0]=SUM("Effective_Production");                        
RESULT(v[0])


EQUATION("Productive_Capacity_Sector")
/*
Sum of the Productive Capacity 
*/
	v[0]=SUM("Productive_Capacity");                     
RESULT(v[0])


EQUATION("Sum_Market_Share")
/*
Sector Variable
Sum of the Market shares: this variable works to verify the Fischer Equation
*/
	v[0]=SUM("Market_Share");
RESULT(v[0])


EQUATION("Sum_Effective_Market_Share")
/*
Sector Variable
*/
	v[0]=SUM("Effective_Market_Share");
RESULT(v[0])


EQUATION("Employment_Sector")
/*
Sector Variable
*/
	v[0]=SUM("Firm_Employment");                                        //initializes the CYCLE
RESULT(v[0])



EQUATION("Depreciation_Expenses_Sector")
/*
Sector average debt rate will be the average of firms productivity weighted by their market shares
*/
	v[0]=SUM("Depreciation_Expenses");
RESULT(v[0])


/*****SECTOR AVERAGES AND MAX*****/


EQUATION("Avg_Price")
/*
Average weighted by firm's market share
*/
	v[0]=WHTAVE("Price", "Market_Share");
RESULT(v[0])


EQUATION("Avg_Competitiveness")
/*
Sector Variable
*/
	v[0]=0;                                         //initializes the CYCLE
	CYCLE(cur, "FIRMS")                             //CYCLE trought all firms in the sector
	{
		v[1]=VS(cur, "Competitiveness");              //firm's competitiveness
		v[2]=VLS(cur, "Market_Share", 1);             //firm's market share in the last period
		v[0]=v[0]+v[1]*v[2];                          //sector average competitiveness will be a average of firms competitiveness weighted by their respective market shares
	}
RESULT(v[0])


EQUATION("Max_Quality")
/*
Maximum firm quality of the sector.
*/
	v[0]=MAX("Quality");
RESULT(v[0])


EQUATION("Max_Productivity")
/*
Maximum productivity of the sector will be the higher between firm's frontier productivities
*/
	v[0]=MAX("Frontier_Productivity");          
RESULT(v[0])


EQUATION("Avg_Quality_Sector")
/*
Average of the firm's quality weighted by their effecitve market share
*/
	v[0]=WHTAVE("Quality", "Effective_Market_Share");
RESULT(v[0])


EQUATION("Avg_Productivity_Sector")
/*
Sector average productivity will be the average of firms productivity weighted by their market shares
*/
	v[0]=WHTAVE("Firm_Avg_Productivity", "Market_Share");
RESULT(v[0])


EQUATION("Avg_Debt_Rate_Sector")
/*
Sector average debt rate will be the average of firms productivity weighted by their market shares
*/
	v[0]=WHTAVE("Debt_Rate", "Market_Share");
RESULT(v[0])


EQUATION("Avg_Profit_Margin_Sector")
/*
Sector Average Markup 
*/
	v[0]=WHTAVE("Profit_Margin", "Market_Share");
RESULT(v[0])


EQUATION("Avg_M_Sector")
/*
Average weighted by firm's market share
*/
	v[0]=WHTAVE("M", "UC");
	v[1]=SUM("UC");
	v[2]=v[0]/v[1];
RESULT(v[2])


EQUATION("Avg_Markup_Sector")
/*
Average weighted by firm's market share
*/
	v[0]=WHTAVE("Markup", "Market_Share");
RESULT(v[0])


EQUATION("Avg_Capacity_Utilization_Sector")
/*
Average weighted by firm's market share
*/
	v[0]=WHTAVE("Capacity_Utilization_Firm", "Market_Share");
RESULT(v[0])



