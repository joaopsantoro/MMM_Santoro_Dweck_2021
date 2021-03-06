
EQUATION("Init")

CYCLE(cur, "SECTORS")
{

	CYCLES(cur, cur1, "FIRMS")
	{
		CYCLES(cur1, cur2, "INPUTS")
		{
			v[1]=VS(cur2, "id_input_sector");
			if (v[1]==2)
			WRITES(cur2, "capital_output_ratio", 2.5);
			else
			WRITES(cur2, "capital_output_ratio", 0);
		}
	}
}
PARAMETER
RESULT(0)



EQUATION("Time_Step")
/*
Root Variable
Determines the order in which the variable will be calculated in each time step
*/

/*****PRODUCTIVE CAPACITY*****/

V("Effective_Productive_Capacity_Variation_Function");
V("Effective_Productive_Capacity_Variation");
V("Learning");
V("Capital_Good_Productivity");
V("Max_Capital_Goods_Productivity"); 
V("Productive_Capacity");                   
 

/*****PLANNED PRODUCTION*****/
V("Gama");                                             //sector variable
V("Expected_Sales");                                   //firm variable
V("Planned_Production");                               //firm variable


/*****EFFECTIVE PRODUCTION AND EXTRA INPUT DEMAND*****/

V("Min_Available_Inputs_Ratio");                       //firm variable
V("Min_Available_Inputs_Ratio_Intermediate_Sector");   //firm variable
V("Quality");                                          //firm variable
V("Competitiveness");                                  //firm variable
V("Avg_Competitiveness");															 //Sector Variable
V("Market_Share");                                     //firm variable
V("Required_Inputs");                                  //firm variable
V("Input_Demand_Production_Period");                   //firm variable 
V("Input_Demand_Next_Period");                         //firm variable
V("Domestic_Intermediate_Demand");                     //macro variable
V("Intermediate_Production");                          //macro variable
V("Intermediate_Production_Firm");                     //firm variable
V("Effective_Production");    
V("Firm_Avg_Productivity");

/*************PRICE DECISION******************/

V("Target_Real_Wage");                                //sector variable
V("Wage");                                             //sector variable
V("Foreign_Price");                                    //sector variable
V("desired_degree_capacity_utilization");							 //sector parameter
V("depreciation_rate");
V("productive_capacity_cost");
V("imitation_revenue_proportion_sector");
V("Exchange_Rate");                                    //external sector variable
V("Input_Cost");                                       //input variable
V("Intermediate_Goods_Costs");                         //firm variable
V("UDC");                          					        	 //firm variable
V("NUC");                          					           //firm variable
V("M");							                                   //firm variable
V("theta");  						                                  //firm variable
V("Price");                                            //firm variable
V("Avg_Price");                                        //sector variable

 
/*****GOVERNMENT EXPENSES (AUTONOMOUS)*****/
V("Interest_Rate");                                    //government variable
V("Government_Wages");                                 //government variable
V("Desired_Government_Investment");                    //government variable
V("Desired_Government_Consumption");                   //government variable

/*****EXPORTS*****/
V("Exports");                                          //sector variable 


/*****CAPITAL GOODS DEMAND*****/
V("Demand_Capital_Goods");                             //firm variable (?)
V("Government_Investment");                            //government variable
V("Domestic_Capital_Demand");                          //macro variable
V("Effective_Orders_Capital_Firm");                    //sector variable
V("Effective_Orders_Capital_Goods_Firm");              //firm variable


/*****CONSUMPTION DEMAND*****/
V("Government_Consumption");                           //government variable
V("Autonomous_Consumption_Variation_Rate");            //macro variable
V("Domestic_Consumption_Demand");                      //macro variable
V("Effective_Orders_Sector");                          //sector variable
V("Effective_Orders_Consumption_Firm");                //sector variable


/*****EFFECTIVE ORDERS, SALES AND PROFITS*****/
V("Effective_Orders");                                 //firm variable 
V("Sales");                                            //firm variable
V("Delivery_Delay");                                   //firm variable
V("Sales_Sector");                                     //sector variable
V("Inventories");                                      //firm variable
V("Effective_Market_Share");                           //firm variable
V("Revenue");                                          //firm variable
V("Indirect_Tax");                                     //firm variable
V("Depreciation_Expenses");                            //firm variable
V("Profits");                                          //firm variable
V("Price_Capital_Goods");                              //macro variable
V("Spread_Firm");                                      //firm variable
V("Interest_Rate_Firm");                               //firm variable
V("Retained_Profits");                                 //firm variable
V("Profits_Distribution");                             //firm variable

/*****INCOME GENERATION*****/
V("Distributed_Profits");                              //macro variable
V("Total_Retained_Profits");                           //macro variable
V("Total_Wages");                                      //macro variable
V("Demand_Met");                                       //sector variable
V("Extra_Imports");                                    //sector variable   
V("Demand_Met_By_Imports");                            //sector variable
V("Class_Nominal_Income");                             //class variable
V("Class_Real_Income");                                //class variable

/*****R&D*****/
V("Innovation_Productivity");                          //firm variable
V("Imitation_Productivity");                           //firm variable
V("Frontier_Productivity");                            //firm variable
V("Innovation_Quality");                               //firm variable
V("Imitation_Quality");                                //firm variable
V("Potential_Quality");                                //firm variable
V("Pay_Test_Quality");                                 //firm variable

/*****INVESTMENT DECISIONS*****/
V("Expected_Sales_Long_Term");                         //firm variable
V("Depreciation_Productive_Capacity");                 //firm variable
V("Desired_Productive_Capacity_Variation");            //firm variable
V("Desired_Autonomous_Investment");                    //firm variable
V("Desired_Investment_Expenses");                      //firm variable

/*****FINANCIAL CONSTRAINTS*****/
V("Internal_Funds");                                   //firm variable
V("Pool_Financial_Assets");                            //firm variable
V("Pool_Debt");                                        //firm variable
V("Funds");                                            //firm variable 

/*****EFFECTIVE INVESTMENT*****/
V("Investment_Expenses_1");                            //firm variable
V("Investment_Expenses_2");                            //firm variable
V("Investment_Expenses");                              //firm variable 
V("Demand_Productive_Capacity");                       //firm variable  
V("Available_Funds_Replacement");                      //firm variable 
V("Available_Funds_Replacement_Rest");                 //firm variable
V("Desired_Autonomous_Investment_Quality");            //firm variable
V("Autonomous_Investment_Quality");                    //firm variable
V("Demand_Productive_Capacity_Quality");               //firm variable 
V("Productive_Capacity_Variation");                    //firm variable
V("Effective_Productive_Capacity_Variation");          //firm variable
V("Replecement_2");                                    //firm variable 
V("Capital_Good_Replacement");                         //firm variable
V("Replecement");                                      //firm variable
V("Financial_Asset_2");                                //firm variable

/*****DEBT*****/
V("Debt_2");                                           //firm variable
V("Debt");                                             //firm variable  
V("Capital");                                          //firm variable  
V("Debt_Rate");                                        //firm variable

/*****ENTRY&EXIT*****/
V("Capital_Good_Production");                          //capital variable
V("Avg_Productivity_Sector");                          //sector variable
V("Total_Investment_Expenses");                        //sector variable
V("Number_Exit");                                      //sector variable
V("To_Entry");                                         //sector variable
V("Productive_Capacity_Exit");                         //sector variable
V("Productive_Capacity_To_Entry");                     //sector variable 
V("Entry");

/*****MACRO RESULTS*****/
V("Aggregate_Inventories");                            //macro variable
V("Gross_Value_Production");                           //macro variable
V("Aggregate_Rate_Capacity_Utilization");              //macro variable
V("Real_Q_Consumption");                                    //macro variable                 
V("Real_Q_Investment");                                     //macro variable
V("Indirect_Taxes");                                   //government variable
V("Profit_Share");                                     //macro variable
V("Wage_Share");                                       //macro variable
V("Q_GDP");                                            //macro variable
V("GDP");                                              //macro variable
V("Growth_rate");                                      //macro variable
V("Price_Index");                                      //macro variable
V("Consumer_Price_Index");                             //macro variable
V("Real_Q_GDP");                                       //macro variable
V("Real_Growth_Rate");                                 //macro variable
V("Real_Q_Consumption");                                    //macro variable                 
V("Real_Q_Investment");                                     //macro variable
V("Likelihood_Crisis");                                //macro variable
V("Employment_Sector");                                //sector variable
V("Total_Employment");                                 //macro variable


RESULT(t)




