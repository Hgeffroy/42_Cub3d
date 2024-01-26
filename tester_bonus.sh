#!/bin/bash

ROUGE='\033[31m'
VERT='\033[32m'
RESET='\033[0m'

# Spécifie le dossier contenant les fichiers à traiter
dossier="./assets/maps_test"

# Spécifie le programme à exécuter
programme_a_executer="./cub3D_bonus"

# Vérifie si le dossier existe
if [ ! -d "$dossier" ]; then
  echo "Le dossier n'existe pas."
  exit 1
fi

# Boucle à travers les fichiers du dossier
for fichier in "$dossier"/*; do
  # Vérifie si le fichier est un fichier régulier
  if [ -f "$fichier" ]; then
    # Extrait la première lettre du nom de fichier
    premiere_lettre=$(basename "$fichier" | cut -c 1)

    # Exécute le programme en passant le fichier en tant que paramètre
    if [ "$premiere_lettre" = "b" ]; then
      "$programme_a_executer" "$fichier" #2>/dev/null
      if [ $? -eq 0 ]; then
        printf "${ROUGE}✗ Bad: ${RESET}$fichier\n"
      else
        printf "${VERT}✓ Good: ${RESET}$fichier\n"
      fi
    elif [ "$premiere_lettre" = "g" ]; then
      "$programme_a_executer" "$fichier" #2>/dev/null
      if [ $? -eq 1 ]; then
        printf "${ROUGE}✗ Bad: ${RESET}$fichier\n"
      else
        printf "${VERT}✓ Good: ${RESET}$fichier\n"
      fi
    fi
  fi
done

dossier="./maps"

# Boucle à travers les fichiers du dossier
for fichier in "$dossier"/*; do
  # Vérifie si le fichier est un fichier régulier
  if [ -f "$fichier" ]; then
    # Extrait la première lettre du nom de fichier
    premiere_lettre=$(basename "$fichier" | cut -c 1)

    # Exécute le programme en passant le fichier en tant que paramètre
    if [ "$premiere_lettre" = "b" ]; then
      "$programme_a_executer" "$fichier" #2>/dev/null
      if [ $? -eq 0 ]; then
        printf "${ROUGE}✗ Bad: ${RESET}$fichier\n"
      else
        printf "${VERT}✓ Good: ${RESET}$fichier\n"
      fi
    elif [ "$premiere_lettre" = "g" ]; then
      "$programme_a_executer" "$fichier" #2>/dev/null
      if [ $? -eq 1 ]; then
        printf "${ROUGE}✗ Bad: ${RESET}$fichier\n"
      else
        printf "${VERT}✓ Good: ${RESET}$fichier\n"
      fi
    fi
  fi
done