# Day 1 - part 2 - find the three entries that sum up to 2020
# and then multiply them together

# the puzzle states the input from part1 is to be used.
my_expenses = open('expense_entries.txt', 'r')
expenses_report = my_expenses.readlines()

for i in range(len(expenses_report)):
	
	entry1 = int(expenses_report[i])
	
	if entry1 < 2020:
	
		sub_total = 2020 - entry1
	
		for j in range(i + 1, len(expenses_report)):
	
			entry2 = int(expenses_report[j])
			
			if entry2 < sub_total:
			
				for l in range(j + 1, len(expenses_report)):
				
					entry3 = int(expenses_report[l])
					
					if entry2 + entry3 == sub_total:
						# the puzzle assumes there's only one set of numbers that fulfill the condition.	
						print(entry1 * entry2 * entry3)
						exit()
