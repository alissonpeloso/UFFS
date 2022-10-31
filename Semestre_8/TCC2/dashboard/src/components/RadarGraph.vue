<template>
	<apexchart width="500" type="radar" :options="chartOptions" :series="series"></apexchart>
</template>

<script>
export default {
	data: function () {
		return {
			chartOptions: {
				theme: {
					mode: "dark",
				},
				chart: {
					id: "vuechart-example",
					background: '#ffffff00',
					width: "100%",
				},
				xaxis: {
					categories: ["2\‘", "5\‘", "15\‘", "30\‘"],
				},
				yaxis: {
					show: false,
				},
				plotOptions: {
					radar: {
						polygons: {
							strokeColor: '#e8e8e8',
							fill: {
								colors: ['#e6e6e6', '#f5f5f5']
							}
						}
					}
				},
				fill: {
					opacity: 0.5,
					colors: ['#00A281'],
				},
				stroke: {
					show: true,
					width: 3,
					colors: ['#00A281'],
					dashArray: 0
				},
				markers: {
					size: 4,
					hover: {
						size: 5
					},
					colors: ['#00A281'],
				},
				tooltip: {
					theme: 'dark',
				},
				title: {
					text: "Compra",
					align: 'center',
					margin: 10,
					offsetX: 0,
					offsetY: 0,
					floating: false,
					style: {
						fontSize: '24px',
						fontWeight: 'lighter',
						fontFamily: 'Roboto',
						color: '#F5F5F5'
					},
				}
			},
			series: [
				{
					name: "indicator",
					data: [1.45, 0.63, 8.74, 3.96],
				},
			],
		};
	},
};
</script>