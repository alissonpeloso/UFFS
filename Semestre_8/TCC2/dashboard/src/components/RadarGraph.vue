<template>
    <apexchart
        type="radar"
        :options="chartOptions"
        :series="series"
        height="40%"
    ></apexchart>
</template>

<script>
export default {
    props: {
        // TODO: get data from api
        // data: {
        //     type: Array,
        //     required: true
        // },
        title: {
            type: String,
            required: true
        },
        color: {
            type: String,
            required: true
        }
    },
    data: function () {
        return {
        chartOptions: {
            theme: {
                mode: "dark",
            },
            chart: {
                id: "vuechart-example",
                background: "#ffffff00",
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
                        strokeColor: "#e8e8e8",
                        fill: {
                            colors: ["#e6e6e6", "#f5f5f5"],
                        },
                    },
                },
            },
            fill: {
                opacity: 0.5,
                colors: [this.color],
            },
            stroke: {
                show: true,
                width: 3,
                colors: [this.color],
                dashArray: 0,
            },
            markers: {
                size: 4,
                hover: {
                    size: 5,
                },
                colors: [this.color],
            },
            tooltip: {
                theme: "dark",
            },
            title: {
                text: this.title,
                align: "center",
                margin: 10,
                offsetX: 0,
                offsetY: 0,
                floating: false,
                style: {
                    fontSize: "24px",
                    fontWeight: "lighter",
                    fontFamily: "Roboto",
                    color: "#F5F5F5",
                },
            },
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