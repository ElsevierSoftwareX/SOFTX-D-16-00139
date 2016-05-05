#!/bin/bash
#==============================================================================
WGETOP=" --trust-server-names -q ";
SPATH="ftp://ftp.plantbiology.msu.edu/pub/data/Eukaryotic_Projects/o_sativa/";
VPATH7="annotation_dbs/pseudomolecules/version_7.0/"
VER2="7";
# =============================================================================
# VERSION 7
wget $WGETOP $SPATH/$VPATH7/chr01.dir/Chr1.seq  -O OS$VER2-1.fa
wget $WGETOP $SPATH/$VPATH7/chr02.dir/Chr2.seq  -O OS$VER2-2.fa
wget $WGETOP $SPATH/$VPATH7/chr03.dir/Chr3.seq  -O OS$VER2-3.fa
wget $WGETOP $SPATH/$VPATH7/chr04.dir/Chr4.seq  -O OS$VER2-4.fa
wget $WGETOP $SPATH/$VPATH7/chr05.dir/Chr5.seq  -O OS$VER2-5.fa
wget $WGETOP $SPATH/$VPATH7/chr06.dir/Chr6.seq  -O OS$VER2-6.fa
wget $WGETOP $SPATH/$VPATH7/chr07.dir/Chr7.seq  -O OS$VER2-7.fa
wget $WGETOP $SPATH/$VPATH7/chr08.dir/Chr8.seq  -O OS$VER2-8.fa
wget $WGETOP $SPATH/$VPATH7/chr09.dir/Chr9.seq  -O OS$VER2-9.fa
wget $WGETOP $SPATH/$VPATH7/chr10.dir/Chr10.seq -O OS$VER2-10.fa
wget $WGETOP $SPATH/$VPATH7/chr11.dir/Chr11.seq -O OS$VER2-11.fa
wget $WGETOP $SPATH/$VPATH7/chr12.dir/Chr12.seq -O OS$VER2-12.fa
# =============================================================================
echo "Done!"
# =============================================================================
