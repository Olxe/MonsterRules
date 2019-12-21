<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.2.4" name="objects_1" tilewidth="117" tileheight="78" tilecount="4" columns="0">
 <grid orientation="orthogonal" width="1" height="1"/>
 <tile id="0">
  <image width="58" height="74" source="../../Textures/Barrel (1).png"/>
 </tile>
 <tile id="1">
  <image width="58" height="74" source="../../Textures/Barrel (2).png"/>
 </tile>
 <tile id="2" type="filled_barrel">
  <properties>
   <property name="life" type="int" value="100"/>
   <property name="physic" value="static"/>
  </properties>
  <image width="58" height="74" source="../../Textures/Barrel (3).png"/>
 </tile>
 <tile id="3" type="HERO_ARCHER">
  <image width="117" height="78" source="../../Textures/Characters/Heroes/Hero_2/tiledHero2.png"/>
 </tile>
</tileset>
