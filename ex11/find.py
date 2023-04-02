#!/usr/bin/python3
import requests

poke_name = input("Enter the name of a pokemon: ").strip().lower()

if poke_name == "":
	print("You did not enter a name.")
	exit()
try:
	request = requests.get("https://pokeapi.co/api/v2/pokemon/" + poke_name)
except requests.HTTPError:
	print("A HTTP error occurred.")
	exit()
if request.status_code == 404:
	print("Pokemon not found.")
	exit()
print("Name: " + request.json()["name"].title())
print("Abilities:")
for ability in request.json()["abilities"]:
	print("-", ability["ability"]["name"].title())
