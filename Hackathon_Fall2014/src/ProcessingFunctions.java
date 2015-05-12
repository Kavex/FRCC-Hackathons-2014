
import java.io.*;

public class ProcessingFunctions {
	
	//owner's algorithm to generate his store selling price,
	//given to us later
	void algorithm(double used_low, double new_low) {
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
		System.out.println("the price is " + price);
	}
	double whichHigher(double newPrice, double usedPrice) {
		if (newPrice >= usedPrice) {
			return newPrice;
		}
		else{
			return usedPrice;
		}
	}
	
	//take all the information about the product and write it
	//to a csv file
	void writeToFile(int upc, String name, double lowPrice,
			double highPrice, String department, String type) {

		try {
			String fileName = "TestFile.csv";
			FileWriter writer = new FileWriter(fileName, true);
			writer.write(upc + "," + name + "," + lowPrice
					+ "," + highPrice + "," + department + "," + type + "\n");
			writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
