# Home Assistant IoT Library
Fonctionne avec une integration perso home assistant. reposit séparé.


# Description
Ce projet est une bibliothèque de classes pour la création de programmes pour des objets connectés intégrés à Home Assistant via une intégration personnalisée. Il propose un ensemble de classes abstraites définissant le comportement des objets qui peuvent être liés à l'intégration, ainsi que des implémentations spécifiques à différentes cartes de développement.

L'objectif est de fournir un ensemble de classes d'objets prêts à être déployés sur les cartes de manière facile et transparente.

# Installation
Pour installer et utiliser cette bibliothèque, suivez les étapes ci-dessous :

Clonez ce dépôt sur votre machine locale.
Créez un fichier settings.h à la racine du projet en utilisant FactorySettings comme modèle pour les informations de configuration nécessaires.
Note : settings.h ne sera pas inclus dans le dépôt car il contient des informations sensibles.

# Utilisation
Une fois le projet installé, créez une instance de l'objet que vous souhaitez utiliser dans IoT.cpp. Fournissez les paramètres qui correspondent aux informations de configuration spécifiées dans settings.h. L'objet devrait alors être capable de générer une instance qui utilise les classes adaptées au matériel et aux fonctionnalités présentes sur l'objet.

# Contribution
Les contributions à ce projet sont les bienvenues. Si vous souhaitez contribuer, veuillez créer un fork du projet, effectuer vos modifications et soumettre une pull request. Toutes les contributions seront examinées et, si elles sont jugées appropriées, intégrées au projet.

# Licence
Ce projet est distribué sous la licence MIT. Pour plus d'informations, veuillez consulter le fichier LICENSE inclus dans ce dépôt.

# Support
Si vous rencontrez des problèmes ou avez des questions concernant ce projet, n'hésitez pas à me contacter via GitHub.

