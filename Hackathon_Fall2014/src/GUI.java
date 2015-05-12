import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class GUI extends JFrame {
	JPanel panel1 = new JPanel(new GridBagLayout());
	JPanel tablePanel = new JPanel();
	GridBagConstraints gbc = new GridBagConstraints();

	JLabel upcName = new JLabel("UPC number");
	JLabel sell = new JLabel("Sell price");
	JLabel tradeCredit = new JLabel("Trade credit");
	JLabel tradeCash = new JLabel("trade cash");
	JButton number = new JButton("Test");
	JButton show = new JButton("Show constants");
	JTextField upc = new JTextField("UPC number or name", 20);
	// JTable table = new JTable(rows, column);
	ProcessingFunctions process = new ProcessingFunctions(); // for writing to a
																// file
	private int upcNum;
	private double sellPrice = 1;
	private double tradeInCredit = 1;
	private double tradeInCash = 1;
	String[] columnNames = { "UPC", "ASIN", "Name", "Department", "Type",
			"Credit", "Sell" };

	Object[][] data = { { "0KHB975H239", "$25.00", "0974652873", "Blu-Ray",
			"Movie", "21.00", "43.00", "Batman", "$20.00", "$25.00" }, };
	JTable table = new JTable(data, columnNames);
	JScrollPane tableScrollPane = new JScrollPane(table);

	JRadioButton upcButton = new JRadioButton("ASIN / UPC");
	JRadioButton nameButton = new JRadioButton("Name");
	ButtonGroup group = new ButtonGroup();

	public GUI() {
		super("Database Test");
		Processing myClass = new Processing();
		
		
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setSize(1600, 900);
		group.add(upcButton);
		group.add(nameButton);
		upcButton.setSelected(true);
		// gbc.anchor = GridBagConstraints.NORTHWEST;

		// when you click this button, write the upc number to a file
		number.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				try {
					
						//process.writeToFile(0, upc.getText(), 8.2, 4.3, "dep", "dk");
						String upcNumber = upc.getText();
						myClass.setUpc(upcNumber);
						myClass.scraping();
					
						data = getObjects(myClass);
					//data is getting correct information
						gbc.insets = new Insets(10, 14, 15, 15);
						table = new JTable(data, columnNames);
						setCoordinates(0, 1, tableScrollPane);
		
					}
					
				catch (NumberFormatException e) {
					System.out.print("Unable to parse int");
				}
				catch(IOException ex)
				{
					System.out.println(ex.getMessage());
				}
			}
		});
		//786936226331
		
		
		// show the sell price, trade in credit, and trade in cash prices
		show.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				sell.setText(String.valueOf(sellPrice));
				tradeCredit.setText(String.valueOf(tradeInCredit));
				tradeCash.setText(String.valueOf(tradeInCash));


			}
		});

		gbc.insets = new Insets(5, 5, 5, 5);
		setCoordinates(0, 6, upcName);
		setCoordinates(0, 0, upc);
		setCoordinates(2, 1, number);
		setCoordinates(3, 6, show);
		setCoordinates(1, 0, upcButton);
		setCoordinates(2, 0, nameButton);
		setCoordinates(0, 7, sell);
		setCoordinates(1, 7, tradeCredit);
		setCoordinates(2, 7, tradeCash);

		add(panel1);
	}

	// uses grid bag to set the coordinates of each individual widget
	void setCoordinates(int x, int y, JComponent c) {

		gbc.gridx = x;
		gbc.gridy = y;
		panel1.add(c, gbc);
	}

	public Object[][] getObjects(Processing newData) {
		Object[][] data = new Object[1][10];
			data[0][0] = newData.getAmazonIndex();
			data[0][1] = newData.getSellPrice();
			data[0][2] = newData.getUpc();
			data[0][3] = newData.getType();
			data[0][4] = newData.getDepartment();
			data[0][5] = newData.getLowPrice();
			data[0][6] = newData.getHighPrice();
			data[0][7] = newData.getName();
			data[0][8] = newData.getNewPrice();
			data[0][9] = newData.getUsedPrice();
		return data;
	}
}
