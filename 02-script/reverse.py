# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    reverse.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/11 23:39:28 by aguellil          #+#    #+#              #
#    Updated: 2016/03/13 23:36:59 by aguellil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import lldb,os

################################################################################
#                                INITIALIZATION                                #
################################################################################

# Retrieves the rush directory absolute path from any current subdirectory
rdap = os.getcwd();
while not(os.path.isfile(rdap+'/00-init/.lldbinit') \
	or os.path.isfile(rdap+'/01-usage/commandes') \
	or os.path.isfile(rdap+'/02-script/reverse.py')):
	rdap = os.path.abspath(os.path.join(rdap, os.pardir));

# Creates strings for the banner and the example source code
str_aguellil=\
"        ######   ######   #    #   ######   #        #        #   #     \n"+\
"        #    #   #        #    #   #        #        #        #   #     \n"+\
"        ######   #  ###   #    #   ####     #        #        #   #     \n"+\
"        #    #   #    #   #    #   #        #        #        #   #     \n"+\
"        #    #   ######   ######   ######   ######   ######   #   ######\n"
str_ampersand=\
"                                      ##                                \n"+\
"                                     #  #                               \n"+\
"                                      # #  #                            \n"+\
"                                    #    #                              \n"+\
"                                     ####  #                            \n"
str_jwong=\
"                      #   #     #    ####    #    #   ######            \n"+\
"                      #   #     #   #    #   ##   #   #                 \n"+\
"                      #   #  #  #   #    #   # #  #   #  ###            \n"+\
"                  #   #    # # #    #    #   #  # #   #    #            \n"+\
"                  #####     # #      ####    #   ##   ######            \n"
str_example_source_code=\
'// ************************************************************************** //\n'+\
'//                                                                            //\n'+\
'//                                                        :::      ::::::::   //\n'+\
'//   example.cpp                                        :+:      :+:    :+:   //\n'+\
'//                                                    +:+ +:+         +:+     //\n'+\
'//   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        //\n'+\
'//                                                +#+#+#+#+#+   +#+           //\n'+\
'//   Created: 2016/03/12 02:28:38 by aguellil          #+#    #+#             //\n'+\
'//   Updated: 2016/03/12 20:20:53 by jwong            ###   ########.fr       //\n'+\
'//                                                                            //\n'+\
'// ************************************************************************** //\n'+\
'\n'+\
'#include <iostream>\n'+\
'#define MAX 3\n'+\
'\n'+\
'double	average(int min[], int max);\n'+\
'int		max(int min[], int max);\n'+\
'\n'+\
'int		main(void)\n'+\
'{\n'+\
'	int	tab[MAX];\n'+\
'	int count;\n'+\
'\n'+\
'	std::cout << "3 numbers: " << std::endl;\n'+\
'	for ( count = 0; count < MAX ; count++ )\n'+\
'	{\n'+\
'		std::cout << "Next number : ";\n'+\
'		std::cin >> tab[1];// 28: 1 -> count //\n'+\
'	}\n'+\
'	for ( count = 1; count < MAX ; count++ )// 30: 1 -> 0 //\n'+\
'		std::cout << "Value [" << count << "] = " << tab[count] << std::endl;// 31: count -> count + 1 //\n'+\
'	std::cout << "Average = " << average(tab, MAX) << std::endl;\n'+\
'	std::cout << "MAX = " << max(tab, MAX) << std::endl;\n'+\
'	return 0;\n'+\
'}\n'+\
'\n'+\
'double 	average(int min[], int max)\n'+\
'{\n'+\
'	double	tmp;\n'+\
'\n'+\
'	tmp = 0.0;\n'+\
'	for (int i = 0; i > max; i++)// 42: > -> < //\n'+\
'		tmp += min[0];// 43: 0 -> i //\n'+\
'	tmp /= max;\n'+\
'	return tmp;\n'+\
'}\n'+\
'\n'+\
'int 	max(int min[], int max)\n'+\
'{\n'+\
'	int	biggest;\n'+\
'\n'+\
'	biggest = 0;// 52: 0 -> min[0] //\n'+\
'	for (int i = 1; i < max; i++)\n'+\
'		if (biggest <= min[i])\n'+\
'			biggest = min[0];// 55: 0 -> i //\n'+\
'	return biggest;\n'+\
'}\n'

# Makes sure the debugger doesn't return from a function until a process stops
lldb.debugger.SetAsync(False)

# Tries to retrieve the target indexed by the debugger, but if it fails 
# it returns an invalid one
target = lldb.debugger.GetTargetAtIndex(0)

# Function which checks if the current target is invalid and makes a default one 
# if necessary
def init_target(debugger, command, result, internal_dict):
	global target
	if not(target.IsValid()):
		target = lldb.debugger.CreateTargetWithFileAndArch(rdap+'/01-usage/example',lldb.LLDB_ARCH_DEFAULT)

# Function which launches lldb commands from a list of string commands
# with silent / verbose modes
def lldb_execute_commands(debugger, command, result, internal_dict):
	pass

# Makes lldb commands from the essential functions
def __lldb_init_module (debugger, internal_dict):
	debugger.HandleCommand('command script add -f reverse.part_i Part_I')
	debugger.HandleCommand('command script add -f reverse.part_ii Part_II')
	debugger.HandleCommand('command script add -f reverse.part_iii Part_III')
	debugger.HandleCommand('command script add -f reverse.bonus_i Bonus_I')
	debugger.HandleCommand('command script add -f reverse.bonus_ii Bonus_II')
	debugger.HandleCommand('command script add -f reverse.bonus_iii Bonus_III')

################################################################################
#                                PART I FUNCTIONS                              #
################################################################################

# Function which takes care of Part I
def part_i(debugger, command, result, internal_dict):
	part_i_change_prompt(lldb.debugger, command, result, internal_dict)
	part_i_set_intel_syntax(lldb.debugger, command, result, internal_dict)
	part_i_display_banner(lldb.debugger, command, result, internal_dict)

# Function which changes 'lldb' by the Team Leader's name in the prompt
def part_i_change_prompt(debugger, command, result, internal_dict):
	debugger.HandleCommand('settings set prompt "(aguellil) "')

# Function which sets the Intel Syntax
def part_i_set_intel_syntax(debugger, command, result, internal_dict):
	debugger.HandleCommand('settings set target.x86-disassembly-flavor intel')

# Function which displays the banner
def part_i_display_banner(debugger, command, result, internal_dict):
	print('\n'+str_aguellil+'\n'+str_ampersand+'\n'+str_jwong)

################################################################################
#                               PART II FUNCTIONS                              #
################################################################################

# Function which takes care of Part II
def part_ii(debugger, command, result, internal_dict):
	part_ii_create_example_source(debugger, command, result, internal_dict)
	part_ii_create_example_binary(debugger, command, result, internal_dict)

# Function which creates the example.cpp file in safe mode (doesn't overwrite)
def part_ii_create_example_source(debugger, command, result, internal_dict):
	if (os.path.isfile(rdap+'/01-usage/example.cpp')):
		pass
	else:
		file = open(rdap+'/01-usage/example.cpp', 'w')
		file.write(str_example_source_code)
		file.close()

# Function which compiles the example.cpp file
def part_ii_create_example_binary(debugger, command, result, internal_dict):
	os.system('clang++ -Wall -g '+rdap+'/01-usage/example.cpp -o '+rdap+'/01-usage/example')

################################################################################
#                              PART III FUNCTIONS                              #
################################################################################

# Function which takes care of Part III
def part_iii(debugger, command, result, internal_dict):
	init_target(debugger, command, result, internal_dict)
	part_iii_reverse(debugger, command, result, internal_dict)

# Function which prints the reversed name of the target preceded by "FT_"
def part_iii_reverse(debugger, command, result, internal_dict):
	print "FT_"+(target.__str__())[::-1]

################################################################################
#                                    BONUSES                                   #
################################################################################

# Bonus 1 : Part I's  banner in colors
def bonus_i(debugger, command, result, internal_dict):
	print("\033[94m\n"+str_aguellil+"\033[93m\n"+str_ampersand+"\033[92m\n"+str_jwong+"\033[0m")

# Bonus 2 : Part II's commands' automatic launching
def bonus_ii(debugger, command, result, internal_dict):
	init_target(debugger, command, result, internal_dict)
	debugger.HandleCommand('command source --stop-on-continue true --stop-on-error false --silent-run true '+rdap+'/01-usage/commandes')

# Bonus 3 : Additional useful functions in LLDB
def bonus_iii(debugger, command, result, internal_dict):
	debugger.HandleCommand('command script add -f reverse.bonus_iii_cat cat')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_cd cd')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_clang clang')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_clangpp clang++')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_cp cp')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_emacs emacs')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_ls ls')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_mkdir mkdir')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_mv mv')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_pwd pwd')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_rm rm')
	debugger.HandleCommand('command script add -f reverse.bonus_iii_vim vim')
def bonus_iii_cat(debugger, command, result, internal_dict):
	os.system('cat %s' % command)
def bonus_iii_cd(debugger, command, result, internal_dict):
	os.chdir(os.path.expanduser('%s') % command)
def bonus_iii_clang(debugger, command, result, internal_dict):
	os.system('clang %s' % command)
def bonus_iii_clangpp(debugger, command, result, internal_dict):
	os.system('clang++ %s' % command)
def bonus_iii_cp(debugger, command, result, internal_dict):
	os.system('cp %s' % command)
def bonus_iii_emacs(debugger, command, result, internal_dict):
	os.system('emacs %s' % command)
def bonus_iii_ls(debugger, command, result, internal_dict):
	os.system('ls %s' % command)
def bonus_iii_mkdir(debugger, command, result, internal_dict):
	os.system('mkdir %s' % command)
def bonus_iii_mv(debugger, command, result, internal_dict):
	os.system('mv %s' % command)
def bonus_iii_pwd(debugger, command, result, internal_dict):
       	os.system('pwd %s' % command)
def bonus_iii_rm(debugger, command, result, internal_dict):
	os.system('rm %s' % command)
def bonus_iii_vim(debugger, command, result, internal_dict):
	os.system('vim %s' % command)
