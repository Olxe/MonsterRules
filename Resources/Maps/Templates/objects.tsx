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
   <property name="fixedRotation" type="bool" value="false"/>
   <property name="life" type="int" value="100"/>
   <property name="physic" type="int" value="2"/>
  </properties>
  <image width="58" height="74" source="../../Textures/Barrel (3).png"/>
  <objectgroup draworder="index">
   <object id="17" x="8" y="46.0833" width="42.9167" height="17.5"/>
   <object id="22" x="3" y="81.25">
    <polyline points="0,0 26.625,-17.375 58,0"/>
   </object>
   <object id="23" x="14.7273" y="72.5909" width="30.5" height="30.5">
    <ellipse/>
   </object>
   <object id="24" x="0.181818" y="0.909091">
    <polygon points="0,0 26.5455,28.1818 57.0909,-1.63636 38.9091,-22.3636"/>
   </object>
  </objectgroup>
 </tile>
 <tile id="3" type="HERO_ARCHER">
  <properties>
   <property name="physic" type="int" value="2"/>
  </properties>
  <image width="117" height="78" source="../../Textures/Characters/Heroes/Hero_2/tiledHero2.png"/>
  <objectgroup draworder="index">
   <object id="2" x="47.25" y="65.25" width="39.4545" height="10.1819">
    <properties>
     <property name="isSensor" type="bool" value="false"/>
    </properties>
   </object>
  </objectgroup>
 </tile>
</tileset>
