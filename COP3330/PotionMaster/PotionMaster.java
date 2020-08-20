// =============================================================================
// POSTING THIS FILE ONLINE OR DISTRIBUTING IT IN ANY WAY, IN PART OR IN WHOLE,
// IS AN ACT OF ACADEMIC MISCONDUCT AND ALSO CONSTITUTES COPYRIGHT INFRINGEMENT.
// =============================================================================

// Federico Baron	
// fe960661
// COP 3330, Fall 2019

// =============================================================================
//             PotionMaster ~ Sean Szumlanski ~ COP 3330 ~ Fall 2019
// =============================================================================
// Note: I've put this template together for you so you can see one safe way of
// breaking up the method signatures that are too long to put on one line
// without exceeding the limit of 100 characters per line. You can modify
// anything you want in this file.
// =============================================================================


import java.util.*;

public class PotionMaster
{
	// this method maps all the potion names to a set of reagents required
	public static Map<String, Set<String>> potionToReagentsMap(List<PotionInfo> potionsManual)
	{
		// this is the hashmap we are going to return 
		Map<String, Set<String>> map= new HashMap<>();

		// save the length to go through the list of potions
		int len = potionsManual.size();
		for(int i = 0; i < len; i++)
		{
			// create a new set to which we can add all the reagents for every given potion
			Set<String> set = new HashSet<>();
			// for each loop to add all the reagents to a set 
			for(String a: potionsManual.get(i).reagents)
			{
				set.add(a);
			}
			// add the potion with its respective set of reagents to a map
			map.put(potionsManual.get(i).name, set);
		}
		return map;
	}

	// this method maps all the reagents to potions that require them
	public static Map<String, Set<String>> reagentToPotionsMap(List<PotionInfo> potionsManual)
	{
		// this is the hashmap we are going to return 
		Map<String, Set<String>> map = new HashMap<>();

		// save the length to go through the list of potions
		int len = potionsManual.size();
		for(int i = 0; i < len; i++)
		{
			// go through each reagent 
			for(int j = 0; j < potionsManual.get(i).reagents.size(); j++)
			{
				// if the reagent isn't already a key in the map add it 
				if(!map.containsKey(potionsManual.get(i).reagents.get(j)))
				{
					// you have to make a new set since there isn't one yet 
					Set<String> set = new HashSet<>();

					// add the first potion name to this set
					set.add(potionsManual.get(i).name);

					// finally put it in the hashmap
					map.put(potionsManual.get(i).reagents.get(j), set);
				}
				// otherwise if it's in the map
				else
				{
					// make a new set with all the old set's potion names
					Set<String> set = map.get(potionsManual.get(i).reagents.get(j));

					// add the new name
					set.add(potionsManual.get(i).name);

					// add it back into the map
					map.put(potionsManual.get(i).reagents.get(j), set);
				}
			}
		}
		return map;
	}

	// this checks if given a set of regents we can brew a potion 
	public static boolean canBrewPotion(PotionInfo potionInfo, Set<String> reagentsOnHand)
	{
		int len = potionInfo.reagents.size();
		for(int i = 0; i < len; i++)
		{
			if(!reagentsOnHand.contains(potionInfo.reagents.get(i)))
				return false;
		}
		return true;
	}

	// this checks if we can brew the potion but we are passed the string that represents the potion
	public static boolean canBrewPotion(String potionToBrew,
	                                    Map<String, Set<String>> potionToReagentsMap,
	                                    Set<String> reagentsOnHand)
	{
		// make a list of reagents required for the potion 
		Set<String> ingredients = potionToReagentsMap.get(potionToBrew);
		for(String a: ingredients)
		{
			// check if we have all the reagents required
			if(!reagentsOnHand.contains(a))
				return false;
		}
		return true;
	}

	public static Set<String> allPossiblePotions(Map<String, Set<String>> potionToReagentsMap,
	                                             Map<String, Set<String>> reagentToPotionsMap,
	                                             Set<String> reagentsOnHand)
	{
		//make a set to contains all the possible potions we can make
		Set<String> potions = new HashSet<>();
		
		// go through each potion
		for(String a: potionToReagentsMap.keySet())
		{
			// check if the potion can be brewed with the regents on hand. if so, add it 
			if(canBrewPotion(a, potionToReagentsMap, reagentsOnHand))
				potions.add(a);
		}
		return potions;
	}

	public static double difficultyRating()
	{
		return 1.3;
	}

	public static double hoursSpent()
	{
		return 1.0;
	}
}
