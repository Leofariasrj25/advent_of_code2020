# Day 1: Report Repair

my_expenses = open('expense_entries.txt', 'r')
expense_report = my_expenses.readlines()

for i in range(len(expense_report)):
	
	entry1 = int(expense_report[i])
	
	if entry1 < 2020:
		desired_entry = 2020 - entry1
		
		for j in range(i, len(expense_report)):
			entry2 = int(expense_report[j])
		
			if entry2 == desired_entry:
				print(entry1 * entry2)
				
		

