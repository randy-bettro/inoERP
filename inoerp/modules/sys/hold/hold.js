function setValFromSelectPage(sys_hold_id, combination) {
 this.sys_hold_id = sys_hold_id;
 this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var sys_hold_id = this.sys_hold_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (sys_hold_id) {
	$("#sys_hold_id").val(sys_hold_id);
 }
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
 //selecting Id
 $(".sys_hold_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_hold', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the sys_hold_id on find button click
 $('a.show.sys_hold_id').click(function() {
	var sys_hold_id = $('#sys_hold_id').val();
	$(this).attr('href', modepath() + 'sys_hold_id=' + sys_hold_id);
 });

});
