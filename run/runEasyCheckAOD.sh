#!/bin/sh
NEVENTS=100
OUT_DIR="./tmp_output/"
if [ -d "$OUT_DIR" ] ; then
  rm -rvf $OUT_DIR
fi
INPUT="/gpfs/fs2001/yfukuhar/data/youhei_Zmumu_AOD/Zmumu_noRpcHitWide/DIR_noRpcHitWide_user.yfukuhar.14514992.EXT0._000001.RDO.pool.root/AOD.pool.root"

COMMAND="root -l -b -q '$ROOTCOREDIR/scripts/load_packages.C' 'TestRun.cxx(${NEVENTS}, \"${OUT_DIR}\", \"$INPUT\", \"$DATA_DIRECTORY\")'"

echo "INPUT: "$INPUT
echo "OUT_DIR "$OUT_DIR
echo "COMMAND:"
echo $COMMAND

eval $COMMAND

#echo "root -l -b -q '$ROOTCOREDIR/scripts/load_packages.C' 'TestRun.cxx (\"${OUT_DIR}\", \"$INPUT\", \"$DATA_DIRECTORY\" )' " > "$TMP_SH_DIR/tmp.sh"
#
#eval $COMMAND 2>&1 | tee -a jediTaskID.info
#
#JEDITASKID=$(sed -n '/new jediTaskID=/s/INFO : succeeded. new jediTaskID=//p' jediTaskID.info)
##sed -n '/new jediTaskID/p' tmp_test.txt
#echo ""
#echo ""
#echo "JEDITASKID: ${JEDITASKID}" 2>&1 | tee -a jediTaskID.info
#echo "JEDI TASK URL: https://bigpanda.cern.ch/task/${JEDITASKID}/" 2>&1 | tee -a jediTaskID.info
#echo ""
#echo ""
#
#echo "INFO: Create jediTaskID.info"
#echo ""
#
#cd -
#| /gpfs/fs6001/yfukuhar/workspace/AthenaAnalysis/noRpcHit_21_0/jpsi_HITS_to_RDI/LocalAthena/run/run_grid_mc16_Jpsimumu.sh  unix | utf-8 | sh   73%   39:1
