<?php
	echo "Choose rock, paper, or scissors: ";

	$p1_choice = trim(fgets(STDIN));
	$computer_choice = rand(1,3);

	if ($computer_choice == 1) {
		if ($p1_choice == "rock") {
			echo "Tie! The computer chose rock.\n";
		} elseif ($p1_choice == "paper") {
			echo "Congratulations! You Won! The computer chose rock.\n";
		} elseif ($p1_choice == "scissors") {
			echo "Sorry, you lost. The computer chose rock.\n";
		} else {
			echo "Invalid choice! You chose something other than rock, paper, or scissors.\n";
		}
	} elseif ($computer_choice == 2) {
		if ($p1_choice == "rock") {
			echo "Sorry, you lost. The computer chose paper.\n";
		} elseif ($p1_choice == "paper") {
			echo "Tie! The computer chose paper.\n";
		} elseif ($p1_choice == "scissors") {
			echo "Congratulations! You Won! The computer chose paper.\n";
		} else {
			echo "Invalid choice! You chose something other than rock, paper, or scissors.\n";
		}
	} else {
		if ($p1_choice == "rock") {
			echo "Congratulations! You Won! The computer chose scissors.\n";
		} elseif ($p1_choice == "paper") {
			echo "Sorry, you lost. The computer chose scissors.\n";
		} elseif ($p1_choice == "scissors") {
			echo "Tie! The computer chose scissors.\n";
		} else {
			echo "Invalid choice! You chose something other than rock, paper, or scissors.\n";
		}
	}
?>
