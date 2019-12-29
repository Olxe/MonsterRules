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
   <property name="physic" value="static"/>
  </properties>
  <image width="58" height="74" source="../../Textures/Barrel (3).png"/>
  <objectgroup draworder="index" id="2">
   <object id="3" x="4.57576" y="9.90909" width="50" height="50">
    <properties>
     <property name="isSensor" type="bool" value="false"/>
    </properties>
    <ellipse/>
   </object>
  </objectgroup>
 </tile>
 <tile id="3" type="HERO_ARCHER">
  <properties>
   <property name="physic" value="dynamic"/>
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
