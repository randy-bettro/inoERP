<?php

class bc_static_label extends dbObject {

 public static $table_name = "bc_static_label";
 public static $primary_column = "bc_static_label_id";
 public static $key_column = "label_type";
 public static $module = "bc";
 public static $label_type_a = [
  'GENERIC' => 'Generic',
  'ORG' => 'Organization',
  'INV' => 'Inventory',
  'SUBINV' => 'Sub Inventory',
  'LOCATOR' => 'Locator',
  'ITEM' => 'Item'
 ];
 public $field_a = [
  'bc_static_label_id',
  'label_type',
  'bc_label_format_header_id',
  'status',
  'label_content',
  'sys_printer_id',
  'output_file_path',
  'file_name',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'bc_label_format_header_id',
  'label_type',
 ];
 public $requiredField = [
  'label_type',
  'bc_label_format_header_id',
 ];
 public $pageTitle = " Barcode Static Label"; //page Title
 public $bc_static_label_id;
 public $label_type;
 public $bc_label_format_header_id;
 public $status;
 public $label_content;
 public $sys_printer_id;
 public $output_file_path;
 public $file_name;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_transactionId_associationLevel($header_id, $assoc_level) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE transaction_type_id = :header_id AND association_level = :association_level ";

  $value_a = ['transaction_type_id' => $header_id, 'association_level' => $assoc_level];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public function print_label_inputParameters($data_a = '') {
  $f = new inoform();
  $org_id = !empty($data_a['org_id']) ? $data_a['org_id'] : '';
  $subinventory_id = !empty($data_a['subinventory_id']) ? $data_a['subinventory_id'] : '';
  $stmt = '<ul class="column one_column">';
  switch ($this->label_type) {
   case 'LOCATOR':
    $stmt .='<li><label>Organization : </label>' . $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', '', 'org_id', '', 1) . '</li>';
    $stmt .='<li><label>Sub Inventory : </label>' . $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($org_id), 'subinventory_id', 'subinventory', '', 'subinventory_id') . '</li>';
    $stmt .='<li><label>Locator : </label>' . $f->select_field_from_object('locator_id', locator::find_all_of_subinventory($subinventory_id), 'locator_id', 'locator', '', 'locator_id') . '</li>';
    break;

   case 'SUBINV':
    $stmt .='<li><label>Organization : </label>' . $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', '', 'org_id', '', 1) . '</li>';
    $stmt .='<li><label>Sub Inventory : </label>' . $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($org_id), 'subinventory_id', 'subinventory', '', 'subinventory_id') . '</li>';
    break;

   case 'ORG':
   case 'INV':
    $stmt .='<li><label>Organization : </label>' . $f->select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', '', 'org_id', '', 1) . '</li>';
    break;

   case 'ITEM':
    $stmt .='<li><img src="' . HOME_URL .'themes/images/serach.png" class="select_item_number select_popup clickable">'
    . '<label>Item : </label>' . $f->text_field('item_number', '', '15', 'item_number', 'select_item_number', 1) . '</li>';
    break;

   default :
    break;
  }
  $stmt .= '</ul>';
  return $stmt;
 }

}

?>