#Day 2

passwords = open('password_list.txt', 'r')
passwords = passwords.readlines()

valid_passwords = 0

for i in range(len(passwords)):

	passkey = passwords[i].split()
	
	occurrence_rule = passkey[0].split('-')
	min_occurrences = int(occurrence_rule[0])
	max_occurrences = int(occurrence_rule[1])
	
	target_key = passkey[1].split(':')[0]
	
	key_occurrences = passkey[2].count(target_key)
	
	if key_occurrences >= min_occurrences and key_occurrences <= max_occurrences:
		valid_passwords = valid_passwords + 1
		
print(valid_passwords)
	
	
