<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.2" tiledversion="1.3.1" name="objects_1" tilewidth="117" tileheight="78" tilecount="4" columns="0">
 <grid orientation="orthogonal" width="1" height="1"/>
 <tile id="0">
  <image width="58" height="74" source="../../Textures/Barrel (1).png"/>
 </tile>
 <tile id="1">
  <image width="58" height="74" source="../../Textures/Barrel (2).png"/>
 </tile>
 <tile id="2" type="filled_barrel">
  <properties>
   <property name="fixedRotation" type="bool" value="true"/>
   <property name="life" type="int" value="100"/>
   <property name="physic" type="int" value="0"/>
  </properties>
  <image width="58" height="74" source="../../Textures/Barrel (3).png"/>
  <objectgroup draworder="index" id="4">
   <object id="14" x="2" y="46.6667">
    <polygon points="0,0 10,16 43.3333,16 54,-0.666667"/>
   </object>
  </objectgroup>
 </tile>
 <tile id="3" type="HERO_ARCHER">
  <properties>
   <property name="physic" type="int" value="2"/>
  </properties>
  <image width="117" height="78" source="../../Textures/Characters/Heroes/Hero_2/tiledHero2.png"/>
  <objectgroup draworder="index" id="2">
   <object id="2" x="45.5937" y="64.7271" width="39.4545" height="10.1819">
    <properties>
     <property name="isSensor" type="bool" value="false"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
</tileset>
