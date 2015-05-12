import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;





public class Processing extends ProcessingFunctions {

	public Processing() {
		// TODO Auto-generated constructor stub
	}
	private String title;

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getUpc() {
		return upc;
	}

	public void setUpc(String upc) {
		this.upc = upc;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public String getDepartment() {
		return department;
	}

	public void setDepartment(String department) {
		this.department = department;
	}

	public double getLowPrice() {
		return lowPrice;
	}

	public void setLowPrice(double lowPrice) {
		this.lowPrice = lowPrice;
	}

	public double getHighPrice() {
		return highPrice;
	}

	public void setHighPrice(double highPrice) {
		this.highPrice = highPrice;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	
	public String getAmazonIndex() {
		return amazonIndex;
	}

	public void setAmazonIndex(String amazonIndex) {
		this.amazonIndex = amazonIndex;
	}

	public double getSellPrice() {
		return sellPrice;
	}

	public void setSellPrice(double average) {
		this.sellPrice = average;
	}


	private String amazonIndex;
	private double sellPrice;
	private String upc;
	private String type;
	private String department;
	private double lowPrice;
	private double highPrice;
	private String name;
	private double newPrice;
	private double usedPrice;

	public double getNewPrice() {
		return newPrice;
	}

	public void setNewPrice(double newPrice) {
		this.newPrice = newPrice;
	}

	public double getUsedPrice() {
		return usedPrice;
	}

	public void setUsedPrice(double usedPrice) {
		this.usedPrice = usedPrice;
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GUI brett = new GUI(); //show the window
		brett.setVisible(true);
		ProcessingFunctions p = new ProcessingFunctions();
		p.algorithm(4.5, 4.5);
	}
	
	public static void addToDataBase( 
		    String upc,
		    String title,
		    double used,
		    double newPrice,
		    double sell,
		    double credit,
		    double cash,
		    String department,
		    String type) 
		    {

		        Connection con = null;
		        Connection con2 =null;
		        ResultSet rs = null;

		        String url = "jdbc:mysql://localhost:3306/Hackathon";
		        String user = "root";
		        String password = "zexw1thnoin";
		        PreparedStatement pst = null;
		        
		        Statement st = null;
		        
		    
		        
		        String info= "'"+upc+"','"+title+"','"+used+"','"+newPrice+"','"+sell+"','"+credit+"','"+cash+"','"+department+"','"+type+"'";
		        
		        
		        //System.out.println(info);
		        try {

		            con = DriverManager.getConnection(url, user, password);
		            pst = con.prepareStatement("SELECT * FROM tablename WHERE UPCASIN ='"+upc+"'");
		            rs = pst.executeQuery();
		            //st = con.createStatement();
		       
		            if(!rs.next())
		            {
		            	try {

		                    
		                    con2 = DriverManager.getConnection(url, user, password);

		                    st = con.createStatement();

		                    
		                    String query = "INSERT INTO tablename() VALUES("+info+")";
		                    st.executeUpdate(query);


		                } catch (SQLException ex) {
		                    Logger lgr = Logger.getLogger(Processing.class.getName());
		                    lgr.log(Level.SEVERE, ex.getMessage(), ex);

		                } finally {

		                    try {
		                        if (st != null) {
		                            st.close();
		                        }
		                        if (con2 != null) {
		                            con2.close();
		                        }

		                    } catch (SQLException ex) {
		                        Logger lgr = Logger.getLogger(Processing.class.getName());
		                        lgr.log(Level.SEVERE, ex.getMessage(), ex);
		                    }
		                }
		            }
		            else
		            {
		            	
		            	
		            	try {

		                    
		                    con2 = DriverManager.getConnection(url, user, password);

		                    st = con.createStatement();

		                    
		                    String query = "UPDATE tablename SET USEDPRICE='"+used+"',NEWPRICE='"+newPrice+"',SELLPRICE='"+sell+"',CREDIT= '"+credit+"',CASH = '"+cash+"' WHERE UPCASIN ='"+upc+"'";
		                    st.executeUpdate(query);


		                } catch (SQLException ex) {
		                    Logger lgr = Logger.getLogger(Processing.class.getName());
		                    lgr.log(Level.SEVERE, ex.getMessage(), ex);

		                } finally {

		                    try {
		                        if (st != null) {
		                            st.close();
		                        }
		                        if (con2 != null) {
		                            con2.close();
		                        }

		                    } catch (SQLException ex) {
		                        Logger lgr = Logger.getLogger(Processing.class.getName());
		                        lgr.log(Level.SEVERE, ex.getMessage(), ex);
		                    }
		                }
		            	
		            	
		            	
		            }
		            
		            


		        } catch (SQLException ex) {
		            Logger lgr = Logger.getLogger(Processing.class.getName());
		            lgr.log(Level.SEVERE, ex.getMessage(), ex);

		        } finally {

		            try {
		                if (pst != null) {
		                    pst.close();
		                }
		                if (con != null) {
		                    con.close();
		                }
		                if(rs != null){
		                	rs.close();
		                }

		            } catch (SQLException ex) {
		                Logger lgr = Logger.getLogger(Processing.class.getName());
		                lgr.log(Level.SEVERE, ex.getMessage(), ex);
		            }
		        }
		        
		    }

	public void scraping() throws IOException
	{
		String upc = getUpc();
		Document doc = Jsoup.connect("http://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=" + upc)	//opens upc page
				.userAgent("Mozilla/5.0 (Windows NT 6.2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.69 Safari/537.36")//user agents
				.maxBodySize(0)	//give me all the html
				.get();
		String asin = "0000000000"; //initializing asin
		String documentString = doc.html();//converts html to string
		int startingIndex = 0;	//starting place for substrings
		char testerChar = 'c';	//sentintinel value for loops
		if(documentString.indexOf("asin=") != -1)	//make sure it runs before open
		{
			startingIndex = documentString.indexOf("asin=");	//finds first part of asin
			startingIndex = startingIndex + 5;					//starts at first value
					
			testerChar = documentString.charAt(startingIndex);	//initializes while loop
			while(!((testerChar >= 'A' && testerChar <= 'Z') || (testerChar >= 0 && testerChar <= 9))) //loop for valid entry
			{
				startingIndex++;
				testerChar = documentString.charAt(startingIndex);	//checker
			}
			asin=documentString.substring(startingIndex, startingIndex+10);	//setting asin
		}
							 
		doc = Jsoup.connect("http://www.amazon.com/dp/" + asin)		//opens asin html page
				.userAgent("Mozilla/5.0 (Windows NT 6.2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.69 Safari/537.36")
				.maxBodySize(0)
				.get();
		documentString = doc.html();	//converts html to string
		startingIndex = 0;				//resets starting index to 0
		int count = 0;					//initializes
		int endingIndex = 0;
		double usedPrice = 0;
		double newPrice = 0;
		testerChar = 'c';
		char checkLessThan;
		char checkGreaterThan;
		String numberString = "";
		String titleString = "";
		startingIndex = documentString.indexOf(asin + "/ref=tmm", 0);	//set starting value for new price 
		endingIndex = documentString.indexOf("$", startingIndex);	//find price location
		endingIndex ++;		//counter
		count = endingIndex;	
		while(testerChar!='<')		//stop when you reach < gets length of substring
		{
		
			testerChar = documentString.charAt(count);	
			count++;
			
		}
		
		count = count - endingIndex - 1 ;
		
		numberString = documentString.substring(endingIndex, endingIndex + count);	//gets string of double
		
		newPrice = Double.parseDouble(numberString);		//converts string to double
		
		startingIndex = documentString.indexOf(asin + "/ref=tmm", startingIndex +1);	//same as new but used
		endingIndex = documentString.indexOf("$", startingIndex);
		endingIndex++;
		count =  endingIndex;
		testerChar = 'c';
		while(testerChar!='<')
		{
			
			testerChar= documentString.charAt(count);
			count++;
			
		}
		count = count - endingIndex - 1;
		numberString = documentString.substring(endingIndex, endingIndex + count);
		usedPrice = Double.parseDouble(numberString);
		
		
		
		if(documentString.indexOf("productTitle") != -1)	//doesn't find breaks
		{
			startingIndex = documentString.indexOf("productTitle");	//find first index of
			startingIndex = startingIndex + 12;						//moves to appropriate number
					
			checkLessThan = documentString.charAt(startingIndex);		//initizlize loop value
			while( checkLessThan != '>')								//starts at > finds substring length
			{
				startingIndex++;
				checkLessThan = documentString.charAt(startingIndex);
			}
			endingIndex = startingIndex;
			checkGreaterThan = documentString.charAt(endingIndex);
			while(checkGreaterThan != '<')			//stops at <
			{
				endingIndex++;
				checkGreaterThan = documentString.charAt(endingIndex);
			}
			titleString=documentString.substring(startingIndex  + 1 , endingIndex);
		}
			//System.out.printf("%f %f %s", newPrice, usedPrice, titleString); debug output	
		setLowPrice(usedPrice);
		setHighPrice(newPrice);
		setName(titleString);
		algorithm(usedPrice,newPrice);
	}

	void algorithm(double used_low, double new_low) 
	{
		double price = 0;
		double average = 0;
		if (used_low < 2 || new_low < 4)
		{
			price = 2.95;
		}
		else
		{
			if (new_low / used_low > 5)
			{
				if (used_low < 3)
				{
					price = 4.95;
				}
				else if (used_low < 4)
				{
					price = 6.95;
				}
				else
				{
					price = ((int)(used_low / 5.0 + 0.5)) * 5 + 4.95;
				}
			}
			else
			{
				average = (new_low + used_low) / 2.0;
				if (average > 24)
				{
					price = ((int)(used_low / 5.0 + 0.5)) * 5 + 4.95;
				}
				else if (average > 21)
				{
					price = 19.95;
				}
				else if (average > 18)
				{
					price = 16.95;
				}
				else if (average > 15)
				{
					price = 14.95;
				}
				else if (average > 12)
				{
					price = 12.95;
				}
				else if (average > 9)
				{
					price = 9.95;
				}
				else if (average > 6)
				{
					price = 6.95;
				}
				else if (average > 4)
				{
					price = 4.95;
				}
				else
				{
					price = 2.95;
				}
			}
		}
		setSellPrice(price);
	}
	
}


